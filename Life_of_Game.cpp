#include <stdio.h>		//C ǥ�� ���̺귯�� �Լ� ���� 
#include <windows.h>	//�ܼ� â ���� �Լ� ����
#include <conio.h>		//kbhit() �Լ��� getch() �Լ��� ���� ���� 
#include <string.h>		//���ڿ� ���� �Լ� ����, �迭 ���翡 ���̴� memcpy�� ���� ���� 
void gotoxy(int x, int y);			//Ŀ�� �̵� �Լ� 
void CursorTrue();					//Ŀ�� ���̰� �ϱ� 
void CursorFalse();					//Ŀ�� �� ���̰� �ϱ� 

//ù �ٿ� system("cls")�� ���Խ��� ���ϰ� ��. 
void Game_start();					//���� ���� ȭ�� 
void Loading();						//�ε� ȭ��  
void Game_main();					//���� ���� ȭ��
void Game_rule();					//������ ���� ��Ģ ȭ�� 
void Game_sample();					//������ ���� ���� ȭ�� 
void Game_sample_pg1();
void Game_sample_pg2();
void Game_sample_pg3();
void Game_sample_pg4();
void Game_sample_pg5();
void Game_sample_pg6();
void Game_play();					//������ ���� ���� ȭ�� 
void Game_info();					//������ ���� ���� ȭ�� 

void Teduri();						//�׵θ� 

void Egg();							//�̽��� ���� 

#define COL GetStdHandle(STD_OUTPUT_HANDLE)				// �ܼ�â�� �ڵ����� �ޱ�
#define BLACK SetConsoleTextAttribute(COL, 0x0000);		// ������
#define DARK_BLUE SetConsoleTextAttribute(COL, 0x0001);	// �Ķ���
#define GREEN SetConsoleTextAttribute(COL, 0x0002);		// ���
#define BLUE_GREEN SetConsoleTextAttribute(COL, 0x0003);// û���
#define BLOOD SetConsoleTextAttribute(COL, 0x0004);		// �˺����� 
#define PURPLE SetConsoleTextAttribute(COL, 0x0005);	// �����
#define GOLD SetConsoleTextAttribute(COL, 0x0006);		// �ݻ�
#define ORIGINAL SetConsoleTextAttribute(COL, 0x0007);	// ���� ȸ�� (ORIGINAL CONSOLE COLOR)
#define GRAY SetConsoleTextAttribute(COL, 0x0008);		// ȸ��
#define BLUE SetConsoleTextAttribute(COL, 0x0009);		// �Ķ���
#define HIGH_GREEN SetConsoleTextAttribute(COL, 0x000a);// ���λ�
#define SKY_BLUE SetConsoleTextAttribute(COL, 0x000b);	// �ϴû�
#define RED SetConsoleTextAttribute(COL, 0x000c);		// ������
#define PLUM SetConsoleTextAttribute(COL, 0x000d);		// ���ֻ�
#define YELLOW SetConsoleTextAttribute(COL, 0x000e);	// �����
#define WHITE SetConsoleTextAttribute(COL, 0x000f);		// ���

#define SQUARE printf("��");
#define SPACE printf("  ");

#define CIRCLE printf("��"); 

int pan[36][36] = {										//Game_play()�� ���̴� �� ���������� ���� 
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					};									//tap ����ؼ� ���� ���� ��.  -1: ���õ��� ����, 1: ���õ�. 

int pan_next[36][36] = {								//Game_play()���� �������� �ٲ��� �� 
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
					};									//tap ����ؼ� ���� ���� ��.  -1: ���õ��� ����, 1: ���õ�. 

int x=0, y=0;											//���� ��ġ�� �ʱ�ȭ���� �ʱ� ���ؼ� ���������� ����. 
int velocity=50;										//�ӵ� �ʱ�ȭ���� �ʱ� ���ؼ� ���������� ����. 

int main (void)
{
	system("mode con cols=80 lines=40");	//cols: ����, lines: ����, ���� 2ĭ�� ũ��� ���� 1ĭ�� ũ��� ����
	SetConsoleTitle("Game of Life");		//console�� title ���� 
	CursorFalse();							//Ŀ�� ���� 
	Game_start();	//���� ���� ȭ�� �ҷ����� 
	return 0;		//main �Լ� ����
}

void gotoxy(int x, int y)//
{
    COORD CursorPosition = {x, y};
    SetConsoleCursorPosition(COL, CursorPosition);
}

void CursorTrue()//
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };//CONSOLE_CURSOR_INFO ����ü ���� 
    cursorInfo.dwSize = 1;					//Ŀ�� �β� ���� (1~100) 
    cursorInfo.bVisible = TRUE;				//Ŀ���� ����  
    SetConsoleCursorInfo(COL, &cursorInfo);
}

void CursorFalse()//
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };//CONSOLE_CURSOR_INFO ����ü ���� 
    cursorInfo.dwSize = 1;					//Ŀ�� �β� ���� (1~100) 
    cursorInfo.bVisible = FALSE;			//Ŀ���� ���� 
    SetConsoleCursorInfo(COL, &cursorInfo);
}

void Game_start()//
{
	system("cls");
	int i;
	gotoxy(0, 0);
	DARK_BLUE
	for(i=0;i<40;i++) SQUARE
	
	gotoxy(0, 1);
	for(i=0;i<18;i++) SQUARE
	RED
	SQUARE
	DARK_BLUE
	SQUARE
	SQUARE
	RED
	SQUARE
	DARK_BLUE
	for(i=0;i<18;i++) SQUARE
	
	gotoxy(0, 2);
	for(i=0;i<17;i++) SQUARE
	RED
	for(i=0;i<6;i++) SQUARE
	DARK_BLUE
	for(i=0;i<17;i++) SQUARE
	
	gotoxy(0, 3);
	BLUE
	for(i=0;i<18;i++) SQUARE
	RED
	for(i=0;i<4;i++) SQUARE
	BLUE
	for(i=0;i<18;i++) SQUARE
	
	gotoxy(0, 4);
	for(i=0;i<19;i++) SQUARE
	RED
	SQUARE
	SQUARE
	BLUE
	for(i=0;i<19;i++) SQUARE
	
	gotoxy(0, 5);
	for(i=0;i<40;i++) SQUARE
	
	gotoxy(0, 6);
	BLUE_GREEN
	for(i=0;i<8;i++) SQUARE
	for(i=0;i<4;i++) SPACE
	for(i=0;i<3;i++) SQUARE
	for(i=0;i<3;i++) SPACE
	for(i=0;i<4;i++) SQUARE
	SPACE
	SQUARE
	SPACE
	for(i=0;i<3;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<7;i++) SQUARE
	
	gotoxy(0, 7);
	for(i=0;i<7;i++) SQUARE
	SPACE
	for(i=0;i<6;i++) SQUARE
	SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	for(i=0;i<11;i++) SQUARE
	
	gotoxy(0, 8);
	for(i=0;i<7;i++) SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	for(i=0;i<2;i++) SPACE
	for(i=0;i<2;i++) SQUARE 
	for(i=0;i<5;i++) SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<7;i++) SQUARE
	
	gotoxy(0, 9);
	SKY_BLUE
	for(i=0;i<7;i++) SQUARE
	SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	for(i=0;i<11;i++) SQUARE
	
	gotoxy(0, 10);
	for(i=0;i<8;i++) SQUARE
	for(i=0;i<3;i++) SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<7;i++) SQUARE
	
	gotoxy(0, 11);
	for(i=0;i<40;i++) SQUARE
	
	gotoxy(0, 12);
	for(i=0;i<40;i++) SQUARE
	
	gotoxy(0, 13);
	for(i=0;i<15;i++) SQUARE
	for(i=0;i<3;i++) SPACE
	for(i=0;i<3;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<14;i++) SQUARE
	
	gotoxy(0, 14);
	BLUE_GREEN
	for(i=0;i<2;i++) SQUARE
	GRAY
	for(i=0;i<3;i++) SQUARE
	BLUE_GREEN
	for(i=0;i<9;i++) SQUARE
	SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	for(i=0;i<18;i++) SQUARE
	
	gotoxy(0, 15);
	SQUARE
	GRAY
	for(i=0;i<5;i++) SQUARE
	BLUE_GREEN
	for(i=0;i<8;i++) SQUARE
	SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<14;i++) SQUARE
	
	gotoxy(0, 16);
	SQUARE
	GRAY
	for(i=0;i<5;i++) SQUARE
	BLUE_GREEN
	for(i=0;i<8;i++) SQUARE
	SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	for(i=0;i<18;i++) SQUARE
	
	gotoxy(0, 17);
	BLUE
	SQUARE
	GRAY
	for(i=0;i<5;i++) SQUARE
	BLUE
	for(i=0;i<2;i++) SQUARE
	GRAY
	SQUARE
	BLUE
	for(i=0;i<6;i++) SQUARE
	for(i=0;i<3;i++) SPACE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<13;i++) SQUARE
	GRAY
	for(i=0;i<3;i++) SQUARE
	BLUE
	for(i=0;i<2;i++) SQUARE
	
	gotoxy(0, 18);
	for(i=0;i<2;i++) SQUARE
	GRAY
	for(i=0;i<3;i++) SQUARE
	BLUE
	for(i=0;i<2;i++) SQUARE
	GRAY
	SQUARE
	BLUE
	for(i=0;i<26;i++) SQUARE
	GRAY
	for(i=0;i<5;i++) SQUARE
	BLUE
	SQUARE
	
	gotoxy(0, 19);
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	BLUE
	for(i=0;i<2;i++) SQUARE
	GRAY
	SQUARE
	BLUE
	for(i=0;i<27;i++) SQUARE
	GRAY
	for(i=0;i<5;i++) SQUARE
	BLUE
	SQUARE
	
	gotoxy(0, 20);
	DARK_BLUE
	for(i=0;i<3;i++) SQUARE
	GRAY
	for(i=0;i<3;i++) SQUARE
	DARK_BLUE
	SQUARE
	SPACE
	for(i=0;i<6;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<2;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<2;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	SQUARE
	GRAY
	for(i=0;i<5;i++) SQUARE
	DARK_BLUE
	SQUARE
	
	gotoxy(0, 21);
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	DARK_BLUE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<8;i++) SQUARE
	SPACE
	for(i=0;i<4;i++) SQUARE
	SPACE
	for(i=0;i<6;i++) SQUARE
	SPACE
	for(i=0;i<6;i++) SQUARE
	GRAY
	for(i=0;i<3;i++) SQUARE
	DARK_BLUE
	for(i=0;i<2;i++) SQUARE
	
	gotoxy(0, 22);
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	DARK_BLUE
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<8;i++) SQUARE
	SPACE
	for(i=0;i<4;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<2;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	DARK_BLUE
	for(i=0;i<3;i++) SQUARE
	
	gotoxy(0, 23);
	GREEN
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	GREEN
	for(i=0;i<3;i++) SQUARE
	SPACE
	for(i=0;i<8;i++) SQUARE
	SPACE
	for(i=0;i<4;i++) SQUARE
	SPACE
	for(i=0;i<6;i++) SQUARE
	SPACE
	for(i=0;i<4;i++) SQUARE
	GRAY
	for(i=0;i<4;i++) SQUARE
	GREEN
	for(i=0;i<3;i++) SQUARE
	
	gotoxy(0, 24);
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	GREEN
	for(i=0;i<3;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<2;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	for(i=0;i<2;i++) SQUARE
	SPACE
	for(i=0;i<6;i++) SQUARE
	for(i=0;i<5;i++) SPACE
	SQUARE
	GRAY
	SQUARE
	GREEN
	SQUARE
	GRAY
	SQUARE
	GREEN
	for(i=0;i<3;i++) SQUARE
	
	gotoxy(0, 25);
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	GREEN
	for(i=0;i<29;i++) SQUARE
	GRAY
	SQUARE
	GREEN
	for(i=0;i<2;i++) SQUARE
	GRAY
	SQUARE
	GREEN
	for(i=0;i<3;i++) SQUARE
	
	gotoxy(0, 26);
	HIGH_GREEN
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<32;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<3;i++) SQUARE
	
	gotoxy(0, 27);
	HIGH_GREEN
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<32;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<3;i++) SQUARE
	
	gotoxy(0, 28);
	HIGH_GREEN
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<31;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	SQUARE
	GRAY
	for(i=0;i<3;i++) SQUARE
	
	gotoxy(0, 29);
	HIGH_GREEN
	for(i=0;i<2;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<29;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<5;i++) SQUARE
	
	gotoxy(0, 30);
	GRAY
	for(i=0;i<2;i++) SQUARE
	HIGH_GREEN
	for(i=0;i<3;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<28;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<5;i++) SQUARE
	
	gotoxy(0, 31);
	for(i=0;i<5;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<28;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<5;i++) SQUARE
	
	gotoxy(0, 32);
	for(i=0;i<5;i++) SQUARE
	GRAY
	SQUARE
	HIGH_GREEN
	for(i=0;i<34;i++) SQUARE
	
	gotoxy(0, 33);
	GOLD
	for(i=0;i<8;i++) SQUARE
	for(i=0;i<24;i++) SPACE
	for(i=0;i<8;i++) SQUARE
	
	gotoxy(0, 34);
	for(i=0;i<6;i++) SQUARE
	for(i=0;i<28;i++) SPACE
	for(i=0;i<6;i++) SQUARE
	
	gotoxy(0, 35);
	for(i=0;i<5;i++) SQUARE
	for(i=0;i<30;i++) SPACE
	for(i=0;i<5;i++) SQUARE
	
	gotoxy(0, 36);
	for(i=0;i<5;i++) SQUARE
	for(i=0;i<30;i++) SPACE
	for(i=0;i<5;i++) SQUARE
	
	gotoxy(0, 37);
	for(i=0;i<4;i++) SQUARE
	for(i=0;i<32;i++) SPACE
	for(i=0;i<4;i++) SQUARE
	
	gotoxy(0, 38);
	for(i=0;i<3;i++) SQUARE
	for(i=0;i<34;i++) SPACE
	for(i=0;i<3;i++) SQUARE
	
	gotoxy(0, 39);
	for(i=0;i<3;i++) SQUARE
	for(i=0;i<34;i++) SPACE
	for(i=0;i<3;i++) SQUARE
	
	WHITE
	for(i=0;;i++)	//i�� 1�� ������Ű�鼭 ��� �ݺ�	//Press enter to start ��¦�̴� �ִϸ��̼� ȿ�� 
	{
        if(kbhit() and (GetAsyncKeyState(VK_RETURN))) break;	//Ű�Է��� ������ ���ѷ��� ����	(�Է��� �ִٸ� 1(True), �Է��� ���ٸ� 0(False) �� ��ȯ) //�ٸ� Ű�� �Է��ϸ� �����̴� ȿ���� ������ VK_RETURN(Enter) Ű �Է��� �Ǿ�� ���ѷ��� ����� ���� 
        if(i%80==0)			//i�� 80���� ������ �������� ���� ǥ�� 
		{
			gotoxy(29, 36);
			printf("Press enter to start");
		}
        else if(i%80==40)	//i�� �������� 40�� �� ���� ����
		{
			gotoxy(29, 36);
			printf("                    ");
		}
        Sleep(10); //�ð� ����(10ms)
    }
	
	while(1)
		if((GetAsyncKeyState(VK_RETURN)))
		{
			Loading();	//���ݱ��� enterŰ�� ���� ���� �ִٸ� �ε� â �ҷ���
			break;		//���̻� enterŰ �Է��� ���� �����Ƿ� while�� ���� 
		}
	Game_main();	//������ ���� ���� ȭ�� �ҷ����� 
}

void Loading()//
{
	int percent=0, i;
	system("cls");
	gotoxy(35, 17);
	printf("Loading");
	for(i=0;i<5;i++)
	{
		Sleep(200);
		gotoxy(30+i, 21);
		printf("|");
		percent+=6;
		gotoxy(46, 21);
		printf("%d%%", percent);
	}

	gotoxy(42, 17);
	printf(".");
	for(i=0;i<5;i++)
	{
		Sleep(200);
		gotoxy(35+i, 21);
		printf("|");
		if(i==0) percent+=7;
		else percent+=6;
		gotoxy(46, 21);
		printf("%d%%", percent);
	}

	gotoxy(43, 17);
	printf(".");
	Sleep(1000);
	
	gotoxy(44, 17);
	printf(".");
	Sleep(500);
	for(i=0;i<5;i++)
	{
		Sleep(80);
		gotoxy(40+i, 21);
		printf("|");
		if(i==0) percent+=7;
		else percent+=8;
		gotoxy(46, 21);
		printf("%d%%", percent);
	}
	Sleep(100);
}

void Game_main()
{
	//�ʱ� ȭ�� �ҷ����� 
	system("cls");
	
	WHITE
	gotoxy(34, 6);
	printf("Game of Life"); 
	
	RED
	gotoxy(31, 11);
	printf("���������������������������������� ");
	gotoxy(31, 12);
	printf("��               �� ");
	gotoxy(31, 13);
	printf("��      Rule     �� ");
	gotoxy(31, 14);
	printf("��               �� ");
	gotoxy(31, 15);
	printf("���������������������������������� ");
	
	WHITE
	gotoxy(31, 17);
	printf("���������������������������������� ");
	gotoxy(31, 18);
	printf("��               �� ");
	gotoxy(31, 19);
	printf("��     Sample    �� ");
	gotoxy(31, 20);
	printf("��               �� ");
	gotoxy(31, 21);
	printf("���������������������������������� ");
	
	gotoxy(31, 23);
	printf("���������������������������������� ");
	gotoxy(31, 24);
	printf("��               �� ");
	gotoxy(31, 25);
	printf("��      Play     �� ");
	gotoxy(31, 26);
	printf("��               �� ");
	gotoxy(31, 27);
	printf("���������������������������������� ");
	
	gotoxy(31, 29);
	printf("���������������������������������� ");
	gotoxy(31, 30);
	printf("��               �� ");
	gotoxy(31, 31);
	printf("��      Info     �� ");
	gotoxy(31, 32);
	printf("��               �� ");
	gotoxy(31, 33);
	printf("���������������������������������� ");
	
	gotoxy(31, 35);
	printf("key: ��, ��, enter");
	gotoxy(35, 36);
	printf("restart: r");
	
	int input = getch(), i, n=1;	//���� ���ۿ� ����Ǿ� �ִ� enterŰ Ȥ�� �ٸ� Ű�� �޾� ��������. ���۸� ���� ����. 
	while(1)	//���� ���� : ��� �Է� ���� 
	{
		input = getch();	//�Է� �޴� �Լ�, ASCII�ڵ�� �Է� ���� (input�� int���̱� ����) 
		if(input == 224)	//����Ű�� 2byte��, �� ������ ASCII�ڵ�� 224��. �� ���ڰ� 224��� 
							//VK_UP		(��)	: 224 72
							//VK_LEFT	(��)	: 224 75
							//VK_RIGHT	(��)	: 224 77
							//VK_DOWN	(��)	: 224 80
		{
			input = getch();	//���� ���� ��������
			if(input == 72)		//�� ����Ű �Է� ��
			{
				n-=1;
				if(n==0) n=4;
			}
			else if(input == 80)//�Ʒ� ����Ű �Է� �� 
			{
				n+=1;
				if(n==5) n=1;
			}
			
			if(n==1)			//Rule�� ���������� 
			{
				WHITE
				gotoxy(34, 6);
				printf("Game of Life"); 
				
				RED
				gotoxy(31, 11);
				printf("���������������������������������� ");
				gotoxy(31, 12);
				printf("��               �� ");
				gotoxy(31, 13);
				printf("��      Rule     �� ");
				gotoxy(31, 14);
				printf("��               �� ");
				gotoxy(31, 15);
				printf("���������������������������������� ");
				
				WHITE
				gotoxy(31, 17);
				printf("���������������������������������� ");
				gotoxy(31, 18);
				printf("��               �� ");
				gotoxy(31, 19);
				printf("��     Sample    �� ");
				gotoxy(31, 20);
				printf("��               �� ");
				gotoxy(31, 21);
				printf("���������������������������������� ");
	
				gotoxy(31, 23);
				printf("���������������������������������� ");
				gotoxy(31, 24);
				printf("��               �� ");
				gotoxy(31, 25);
				printf("��      Play     �� ");
				gotoxy(31, 26);
				printf("��               �� ");
				gotoxy(31, 27);
				printf("���������������������������������� ");
				
				gotoxy(31, 29);
				printf("���������������������������������� ");
				gotoxy(31, 30);
				printf("��               �� ");
				gotoxy(31, 31);
				printf("��      Info     �� ");
				gotoxy(31, 32);
				printf("��               �� ");
				gotoxy(31, 33);
				printf("���������������������������������� ");
			}
			else if (n==2)			//Sample�� ���������� 
			{
				WHITE
				gotoxy(34, 6);
				printf("Game of Life"); 
				
				WHITE
				gotoxy(31, 11);
				printf("���������������������������������� ");
				gotoxy(31, 12);
				printf("��               �� ");
				gotoxy(31, 13);
				printf("��      Rule     �� ");
				gotoxy(31, 14);
				printf("��               �� ");
				gotoxy(31, 15);
				printf("���������������������������������� ");
				
				RED
				gotoxy(31, 17);
				printf("���������������������������������� ");
				gotoxy(31, 18);
				printf("��               �� ");
				gotoxy(31, 19);
				printf("��     Sample    �� ");
				gotoxy(31, 20);
				printf("��               �� ");
				gotoxy(31, 21);
				printf("���������������������������������� ");
				
				WHITE
				gotoxy(31, 23);
				printf("���������������������������������� ");
				gotoxy(31, 24);
				printf("��               �� ");
				gotoxy(31, 25);
				printf("��      Play     �� ");
				gotoxy(31, 26);
				printf("��               �� ");
				gotoxy(31, 27);
				printf("���������������������������������� ");
				
				gotoxy(31, 29);
				printf("���������������������������������� ");
				gotoxy(31, 30);
				printf("��               �� ");
				gotoxy(31, 31);
				printf("��      Info     �� ");
				gotoxy(31, 32);
				printf("��               �� ");
				gotoxy(31, 33);
				printf("���������������������������������� ");
			}
			else if (n==3)			//Play�� ���������� 
			{
				WHITE
				gotoxy(34, 6);
				printf("Game of Life"); 
				
				WHITE
				gotoxy(31, 11);
				printf("���������������������������������� ");
				gotoxy(31, 12);
				printf("��               �� ");
				gotoxy(31, 13);
				printf("��      Rule     �� ");
				gotoxy(31, 14);
				printf("��               �� ");
				gotoxy(31, 15);
				printf("���������������������������������� ");
				
				gotoxy(31, 17);
				printf("���������������������������������� ");
				gotoxy(31, 18);
				printf("��               �� ");
				gotoxy(31, 19);
				printf("��     Sample    �� ");
				gotoxy(31, 20);
				printf("��               �� ");
				gotoxy(31, 21);
				printf("���������������������������������� ");
				
				RED
				gotoxy(31, 23);
				printf("���������������������������������� ");
				gotoxy(31, 24);
				printf("��               �� ");
				gotoxy(31, 25);
				printf("��      Play     �� ");
				gotoxy(31, 26);
				printf("��               �� ");
				gotoxy(31, 27);
				printf("���������������������������������� ");
				
				WHITE
				gotoxy(31, 29);
				printf("���������������������������������� ");
				gotoxy(31, 30);
				printf("��               �� ");
				gotoxy(31, 31);
				printf("��      Info     �� ");
				gotoxy(31, 32);
				printf("��               �� ");
				gotoxy(31, 33);
				printf("���������������������������������� ");
			}
			
			else					//Info�� ���������� 
			{
				WHITE
				gotoxy(34, 6);
				printf("Game of Life");
				
				WHITE
				gotoxy(31, 11);
				printf("���������������������������������� ");
				gotoxy(31, 12);
				printf("��               �� ");
				gotoxy(31, 13);
				printf("��      Rule     �� ");
				gotoxy(31, 14);
				printf("��               �� ");
				gotoxy(31, 15);
				printf("���������������������������������� ");
				
				gotoxy(31, 17);
				printf("���������������������������������� ");
				gotoxy(31, 18);
				printf("��               �� ");
				gotoxy(31, 19);
				printf("��     Sample    �� ");
				gotoxy(31, 20);
				printf("��               �� ");
				gotoxy(31, 21);
				printf("���������������������������������� ");
	
				gotoxy(31, 23);
				printf("���������������������������������� ");
				gotoxy(31, 24);
				printf("��               �� ");
				gotoxy(31, 25);
				printf("��      Play     �� ");
				gotoxy(31, 26);
				printf("��               �� ");
				gotoxy(31, 27);
				printf("���������������������������������� ");
				
				RED
				gotoxy(31, 29);
				printf("���������������������������������� ");
				gotoxy(31, 30);
				printf("��               �� ");
				gotoxy(31, 31);
				printf("��      Info     �� ");
				gotoxy(31, 32);
				printf("��               �� ");
				gotoxy(31, 33);
				printf("���������������������������������� ");
			}
		}
		
		else if(input == 13)//VK_RETURN (Enter) : 13
		{
			//���� n���� ����(���� �������� ��ư�� ����) �´� �Լ� ȣ�� 
			WHITE 
			if(n==1)
			{
				Game_rule();
				break;
			}
			else if(n==2)
			{
				Game_sample();
				break;
			}
			else if(n==3)
			{
				Game_play();
				break;
			}
			else
			{
				Game_info(); 
				break;
			}
		}
		
		else if(input == 82 or input == 114)//R: 82, r: 114
		{
			Game_start();
			break;
		}
	}
}

void Game_rule()
{
	Teduri();
	gotoxy(28, 6);
	printf("How to play Life of Game");
	
	gotoxy(13, 9);
	printf("Q: ������ ������ �����ΰ���?");
	gotoxy(13, 10);
	printf("A: ������ ������ �� ȣ�� �ܿ��̰� ����س� ���� �ڵ���");
	gotoxy(16, 11);
	printf("�� ��������, ���� �θ� �˷��� ���� �ڵ��� ��� ��");
	gotoxy(16, 12);
	printf("���Դϴ�.");
	
	gotoxy(13, 14);
	printf("Q: ��� �÷����ϳ���?");
	gotoxy(13, 15);
	printf("A: ���� ������ ���� ���¸� �������� �Ʒ� �� ��Ģ�� ����");
	gotoxy(16, 16);
	printf("���� ������ ���� ���°� �����˴ϴ�.");
	
	gotoxy(14, 18);
	printf("- ���� ������ �̿� �� ��Ȯ�� �� ���� ��� ������ �� ��");
	gotoxy(14, 19);
	printf("���� ��Ƴ���('�¾��').");
	
	gotoxy(14, 20);
	printf("- ��� �ִ� ������ �̿� �߿� �� ���� �� ���� ��� ����");
	gotoxy(14, 21);
	printf("��, �� ������ ��� ��� �ִ� ���¸� �����ϰ�, �̿ܿ���");
	gotoxy(14, 22);
	printf("'�ܷο���', �Ǵ� '���� ������' �׾������.");
	
	gotoxy(13, 25);
	printf("Q. ��� �ϸ� �� ������ ��� �� �ֳ���?");
	gotoxy(13, 26);
	printf("A. �ڽŸ��� ������ ���� ������ ��������. ��վ��.");
	
	gotoxy(13, 29);
	printf("Q. �̽��Ϳ��װ� �����ϳ���?");
	gotoxy(13, 30);
	printf("A. ������ ���� �÷����Ͻø� ����� ã���� �� �ֽ��ϴ�!");
	gotoxy(16, 31);
	printf("ȭ�����ϼ���!");
	
	gotoxy(60, 33);
	printf("Quit: q");
	
	char input;
	while(1)
	{
		input = getch();
		if(input==81 or input == 113)	//Q: 81, q: 113
		{
			Game_main();
			break;
		}
	}
}

void Game_sample()
{
	int input, now_pg=1, change=0;
	Game_sample_pg1();
	while(1)
	{
		input = getch();
	 	if(input == 81 or input == 113)	//Q: 81, q: 113
	 	{
	 		Game_main();
		}
		else if(input == 224)
		{
			input = getch();
			if(input == 75)		//���� ����Ű 
			{
				if(now_pg>1) 
				{
					now_pg-=1;
					change=1;
				}
			}
			else if(input == 77)//������ ����Ű 
			{
				if(now_pg<6) 
				{
					now_pg+=1;
					change=1;
				}
			}
			
			if(change==1)
			{
				if(now_pg==1)
				{
					Game_sample_pg1();
				}
				else if(now_pg==2)
				{
					Game_sample_pg2();
				}
				else if(now_pg==3)
				{
					Game_sample_pg3();
				}
				else if(now_pg==4)
				{
					Game_sample_pg4();
				}
				else if(now_pg==5)
				{
					Game_sample_pg5();
				}
				else if(now_pg==6)
				{
					Game_sample_pg6();
				}
				change=0;
			}
		}
	}
}

void Game_sample_pg1()
{
	Teduri();
	gotoxy(66, 6);
	printf("��");
	gotoxy(31, 6);
	printf("���� (Still Lifes)");
	gotoxy(13, 9);
	printf("- ���");
	gotoxy(17, 11);
	SQUARE
	SQUARE
	gotoxy(17, 12);
	SQUARE
	SQUARE
	gotoxy(13, 14);
	printf("- ����");
	gotoxy(17, 16);
	SPACE
	SQUARE
	SQUARE
	SPACE
	gotoxy(17, 17);
	SQUARE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 18);
	SPACE
	SQUARE
	SQUARE
	SPACE
	gotoxy(13, 20);
	printf("- ������");
	gotoxy(17, 22);
	SPACE
	SQUARE
	SQUARE
	SPACE
	gotoxy(17, 23);
	SQUARE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 24);
	SPACE
	SQUARE
	SPACE
	SQUARE
	gotoxy(17, 25);
	SPACE
	SPACE
	SQUARE
	SPACE
	gotoxy(13, 27);
	printf("- ��Ʈ");
	gotoxy(17, 29);
	SQUARE
	SQUARE
	SPACE
	gotoxy(17, 30);
	SQUARE
	SPACE
	SQUARE
	gotoxy(17, 31);
	SPACE
	SQUARE
	SPACE
	gotoxy(60, 33);
	printf("Quit: q");
	gotoxy(35, 33);
	printf("- page.1 -");
}

void Game_sample_pg2()
{
	Teduri();
	gotoxy(12, 6);
	printf("��");
	gotoxy(66, 6);
	printf("��");
	gotoxy(30, 6);
	printf("������ (Oscillators)");
	gotoxy(13, 9);
	printf("- ������");
	gotoxy(17, 11);
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	gotoxy(17, 12);
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	SQUARE
	SPACE
	gotoxy(17, 13);
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	gotoxy(13, 15);
	printf("- �β���");
	gotoxy(17, 17);
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	gotoxy(17, 18);
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SQUARE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 19);
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	SQUARE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 20);
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SPACE
	gotoxy(13, 22);
	printf("- ���");
	gotoxy(17, 24);
	SQUARE
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SPACE
	SPACE
	gotoxy(17, 25);
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SPACE
	SPACE
	gotoxy(17, 26);
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	gotoxy(17, 27);
	SPACE
	SPACE
	SQUARE
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	gotoxy(60, 33);
	printf("Quit: q");
	gotoxy(35, 33);
	printf("- page.2 -");
}

void Game_sample_pg3()
{
	Teduri();
	gotoxy(12, 6);
	printf("��");
	gotoxy(66, 6);
	printf("��");
	gotoxy(30, 6);
	printf("������ (Oscillators)");
	gotoxy(13, 9);
	printf("- �޻�");
	gotoxy(17, 11);
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	gotoxy(17, 13);
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 14);
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 15);
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 16);
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	gotoxy(17, 18);
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	gotoxy(17, 19);
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 20);
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 21);
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 23);
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SPACE
	
	gotoxy(60, 33);
	printf("Quit: q");
	gotoxy(35, 33);
	printf("- page.3 -");
}

void Game_sample_pg4()
{
	Teduri();
	gotoxy(12, 6);
	printf("��");
	gotoxy(66, 6);
	printf("��");
	gotoxy(30, 6);
	printf("���ּ�  (Spaceships)");
	gotoxy(13, 9);
	printf("- �۶��̴�");
	gotoxy(17, 11);
	SQUARE
	SPACE
	SQUARE
	gotoxy(17, 12);
	SPACE
	SQUARE
	SQUARE
	gotoxy(17, 13);
	SPACE
	SQUARE
	SPACE
	gotoxy(13, 15);
	printf("- �淮 ���ּ� (LWSS)");
	gotoxy(17, 17);
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SQUARE
	gotoxy(17, 18);
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 19);
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	gotoxy(17, 20);
	SQUARE
	SPACE
	SPACE
	SQUARE
	SPACE
	gotoxy(60, 33);
	printf("Quit: q");
	gotoxy(35, 33);
	printf("- page.4 -");
}

void Game_sample_pg5()
{
	Teduri();
	gotoxy(12, 6);
	printf("��");
	gotoxy(66, 6);
	printf("��");
	gotoxy(31, 6);
	printf("���  (Methuselah)");
	gotoxy(13, 9);
	printf("- R-����̳�");
	gotoxy(17, 11);
	SPACE
	SQUARE
	SQUARE
	gotoxy(17, 12);
	SQUARE
	SQUARE
	SPACE
	gotoxy(17, 13);
	SPACE
	SQUARE
	SPACE
	gotoxy(13, 15);
	printf("- �����ϵ�");
	gotoxy(17, 17);
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	gotoxy(17, 18);
	SQUARE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	gotoxy(17, 19);
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	gotoxy(13, 21);
	printf("- ���丮");
	gotoxy(17, 23);
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	gotoxy(17, 24);
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	gotoxy(17, 25);
	SQUARE
	SQUARE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	
	gotoxy(60, 33);
	printf("Quit: q");
	gotoxy(35, 33);
	printf("- page.5 -");
}

void Game_sample_pg6()
{
	Teduri();
	gotoxy(12, 6);
	printf("��");
	gotoxy(33, 6);
	printf("���� ���� ����"); 
	gotoxy(13, 9);
	printf("- �ּ� ������ ���� ���� (10)");
	gotoxy(17, 11);
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	gotoxy(17, 12);
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SQUARE
	gotoxy(17, 13);
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SQUARE
	SPACE
	gotoxy(17, 14);
	SPACE
	SPACE
	SPACE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	gotoxy(17, 15);
	SPACE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	gotoxy(17, 16);
	SQUARE
	SPACE
	SQUARE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	SPACE
	gotoxy(13, 18);
	printf("- �ּ� �������� ���� ���� (2��12)");
	gotoxy(17, 20);
	SQUARE
	SPACE
	SPACE
	SQUARE
	SQUARE
	SPACE
	SQUARE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SQUARE
	gotoxy(17, 21);
	SQUARE
	SQUARE
	SQUARE
	SQUARE
	SQUARE
	SQUARE
	SPACE
	SQUARE
	SQUARE
	SPACE
	SPACE
	SQUARE
	 
	gotoxy(60, 33);
	printf("Quit: q");
	gotoxy(35, 33);
	printf("- page.6 -");
}

void Game_play()
{
	system("cls");
	
	int i, j, input, change_x, change_y, change_cnt, changexy_x, changexy_y; 
	
	int generation=0;
	
	gotoxy(31, 0);
	printf("[[ Game of Life ]]");
	
	for(i=0;i<36;i++)
	{
		gotoxy(4, 2+i);
			
		for(j=0;j<36;j++)
		{ 
			if(i==x and j==y)
			{
				if(pan[i][j]==-1)
				{
					WHITE
					CIRCLE
				}
				else
				{
					RED
					CIRCLE
				}
			}
			else
			{
				if(pan[i][j]==-1)
				{
					WHITE
					SQUARE
				}
				else
				{
					RED
					SQUARE
				}
			}
		}
	}
	
	gotoxy(2, 38);
	printf("Move: ��, ��, ��, ��, Select: space, Start: enter, Stop: Backspace, Reset: r");
	gotoxy(71, 0);
	printf("Quit: q");
	gotoxy(50, 1);
	printf("Use +, - to control Velocity");
	gotoxy(2, 0);
	printf("                             ");
	gotoxy(2, 0);
	printf("Generation: %d", generation);
	gotoxy(2, 1);
	printf("                                      ");
	gotoxy(2, 1);
	printf("Velocity  : %d", velocity);
	while(1)
	{
		input = getch();
		if(input == 82 or input == 114)			//R: 82, r: 114
		{
			for(i=0;i<36;i++)	//�� �ʱ�ȭ 
			{
				for(j=0;j<36;j++)
				{
					pan[i][j]=-1;
				}
			}
			//���� ��ġ �ʱ�ȭ 
			x=0;
			y=0;
			//���� �ʱ�ȭ 
			generation=0;
		}
		else if(input == 45)					//-: 45
		{
			if(velocity>1)
			{
				velocity -=1;
			}
		}
		else if(input == 43)					//+: 43
		{
			if(velocity<100)
			{
				velocity +=1;
			}
		}
		else if(input == 81 or input == 113)	//Q: 81, q: 113
		{
			Game_main();		//���� ȭ�� �ҷ�����
			break; 
		}
		else if(input == 224)
		{
			input = getch();
			if(input == 72)
			{
				if(x!=0) x-=1;
			}
			else if(input == 75)
			{
				if(y!=0) y-=1;
			}
			else if(input == 77)
			{
				if(y!=35) y+=1;
			}
			else if(input == 80)
			{
				if(x!=35) x+=1;
			}
		}
		else if(input == 32)			//VK_SP : �����̽� �� 
		{
			pan[x][y] *= -1;
		}
		
			
		for(i=0;i<36;i++)
		{
			gotoxy(4, 2+i);
			
			for(j=0;j<36;j++)
			{
				if(i==x and j==y)
				{
					if(pan[i][j]==-1)
					{
						WHITE
						CIRCLE
					}
					else
					{
						RED
						CIRCLE
					}
				}
				else
				{
					if(pan[i][j]==-1)
					{
						WHITE
						SQUARE
					}
					else
					{
						RED
						SQUARE
					}
				}
			}
		}
		gotoxy(2, 0);
		printf("                             ");
		gotoxy(2, 0);
		printf("Generation: %d", generation);
		gotoxy(2, 1);
		printf("                                      ");
		gotoxy(2, 1);
		printf("Velocity  : %d", velocity);
		
		int playing_input;
		
		if(input == 13)	//VK_CR: ���� Ű 
		{
			while(1)
			{
				if(kbhit())
				{
					playing_input = getch();
					{
						if(playing_input == 8)			//VK_BS: �齺���̽� 
						{
							break;
						}
						else if(playing_input == 81 or playing_input == 113)	//Q: 81, q: 113
						{
							Game_main();		//���� ȭ�� �ҷ�����
							break; 
						}
						else if(playing_input == 82 or playing_input == 114)	//R: 82, r: 114
						{
							for(i=0;i<36;i++)	//�� �ʱ�ȭ 
							{
								for(j=0;j<36;j++)
								{
									pan[i][j]=-1;
								}
							}
						//���� ��ġ �ʱ�ȭ 
						x=0;
						y=0;
						Game_play();
						break;
						}
						else if(playing_input == 224)	//����Ű 
						{
							input = getch();
							if(input == 72)
							{
								if(x!=0) x-=1;
							}
							else if(input == 75)
							{
								if(y!=0) y-=1;
							}
							else if(input == 77)
							{
								if(y!=35) y+=1;
							}
							else if(input == 80)
							{
								if(x!=35) x+=1;
							}
						}
						else if(playing_input == 43)	//+: ASCII 43
						{
							if(velocity<100)
							{
								velocity +=1;
							}
						}
						else if(playing_input == 45)	//-: ASCII 45
						{
							if(velocity>1)
							{
								velocity -=1;
							}
						}
					}
				}
				gotoxy(2, 1);
				printf("                                      ");
				gotoxy(2, 1);
				printf("Velocity  : %d", velocity);
				for(change_x=0;change_x<36;change_x++)
				{
					for(change_y=0;change_y<36;change_y++)
					{
						change_cnt = 0;
						for(changexy_x=change_x-1;changexy_x<=change_x+1;changexy_x++)
						{
							for(changexy_y=change_y-1;changexy_y<=change_y+1;changexy_y++)
							{
								if(changexy_x != change_x || changexy_y != change_y)
								{
									if(changexy_x!=-1 and changexy_x!=36)
									{
										if(changexy_y!=-1 and changexy_y!=36)
										{
											if(pan[changexy_x][changexy_y] == 1)
											{
												change_cnt += 1;
											}
										}
									}
								}
							}
						}
						if(pan[change_x][change_y] == -1 && change_cnt == 3)
						{
							pan_next[change_x][change_y] = 1;
						}
						else if(pan[change_x][change_y] == 1 && (change_cnt == 2 || change_cnt == 3))
						{
							pan_next[change_x][change_y] = 1;
						}
						else
						{
							pan_next[change_x][change_y] = -1;
						}
					}
				}
				memcpy(pan, pan_next, sizeof(pan_next));
				
				for(i=0;i<36;i++)
				{
					gotoxy(4, 2+i);
					
					for(j=0;j<36;j++)
					{
						if(i==x and j==y)
						{
							if(pan[i][j]==-1)
							{
								WHITE
								CIRCLE
							}
							else
							{
								RED
								CIRCLE
							}
						}
						else
						{
							if(pan[i][j]==-1)
							{
								WHITE
								SQUARE
							}
							else
							{
								RED
								SQUARE
							}
						}
					}
				}
				generation += 1;
				gotoxy(2, 0);
				printf("                             ");
				gotoxy(2, 0);
				printf("Generation: %d", generation);
				
				Sleep(5*(101-velocity));
			}
		}
	}
}

void Game_info()
{
	Teduri();
	
	gotoxy(38, 6);
	printf("Info");
	
	gotoxy(13, 9);
	printf("Name: Life of Game");
	
	gotoxy(13, 11);
	printf("Zero-player game determined by initial state");
	
	gotoxy(13, 14);
	printf("Made by 1203 �����, 1209 �ڹ���");
	
	gotoxy(13, 16);
	printf("October 19th, 2022 ~ November 11st, 2022");
	
	gotoxy(13, 19);
	printf("�������а���б� 1�г� 2�б� ���� ������");
	
	gotoxy(13, 21);
	printf("���� ���� �� ���� ����");
	
	gotoxy(13, 24);
	printf("Username: papa2538");
	
	gotoxy(13, 26);
	printf("Github: https://github.com/papa2538");
	
	gotoxy(13, 28);
	printf("Solved.ac: https://solved.ac/profile/papa2538");
	
	gotoxy(13, 30);
	printf("Codeforces: https://codeforces.com/profile/papa2538");
	
	gotoxy(13, 32);
	printf("Atcoder: https://atcoder.jp/users/papa2538");
	
	gotoxy(60, 33);
	printf("Quit: q");
	
	int input;
	while(1)
	{
		input = getch();
		if(input == 81 or input == 113)	//Q: 81, q: 113
		{
			Game_main();
		}
		else if(input == 224)
		{
			input = getch();
			if(input == 72)
			{
				Egg();
			}
		}
	}
}

void Teduri()
{
	int i, j;
	system("cls");
	gotoxy(10, 5);
	printf("��");
	for(i=0;i<57;i++) printf("��");
	printf("��");
	for(i=6;i<34;i++)
	{
		gotoxy(10, i);
		printf("��");
		for(j=0;j<57;j++) printf(" ");
		printf("��");
	}
	gotoxy(10, 34);
	printf("��");
	for(i=0;i<57;i++) printf("��");
	printf("��");
}

void Egg()
{
	system("cls");
	gotoxy(4, 29);	//1203 ����� ���� 
	printf("Egg");
	gotoxy(11, 14);	//1209 �ڹ��� ���� 
	printf("Egg");
	Sleep(1000);
	Game_info();
}
