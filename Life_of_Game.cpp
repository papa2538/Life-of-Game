#include <stdio.h>		//C ル遽 塭檜粽楝葬 л熱 んл 
#include <windows.h>	//夔樂 璽 婦溼 л熱 んл
#include <conio.h>		//kbhit() л熱諦 getch() л熱蒂 噙晦 嬪п 
#include <string.h>		//僥濠翮 婦溼 л熱 んл, 寡翮 犒餌縑 噙檜朝 memcpy蒂 噙晦 嬪п 
void gotoxy(int x, int y);			//醴憮 檜翕 л熱 
void CursorTrue();					//醴憮 爾檜啪 ж晦 
void CursorFalse();					//醴憮 寰 爾檜啪 ж晦 

//羅 還縑 system("cls")蒂 んл衛麵 らж啪 л. 
void Game_start();					//啪歜 衛濛 �飛� 
void Loading();						//煎註 �飛�  
void Game_main();					//啪歜 詭檣 �飛�
void Game_rule();					//塭檜Щ 啪歜 敘罌 �飛� 
void Game_sample();					//塭檜Щ 啪歜 蕨衛 �飛� 
void Game_sample_pg1();
void Game_sample_pg2();
void Game_sample_pg3();
void Game_sample_pg4();
void Game_sample_pg5();
void Game_sample_pg6();
void Game_play();					//塭檜Щ 啪歜 褒ч �飛� 
void Game_info();					//塭檜Щ 啪歜 薑爾 �飛� 

void Teduri();						//纔舒葬 

void Egg();							//檜蝶攪 縑斜 

#define COL GetStdHandle(STD_OUTPUT_HANDLE)				// 夔樂璽曖 с菟薑爾 嫡晦
#define BLACK SetConsoleTextAttribute(COL, 0x0000);		// 匐薑儀
#define DARK_BLUE SetConsoleTextAttribute(COL, 0x0001);	// だ塢儀
#define GREEN SetConsoleTextAttribute(COL, 0x0002);		// 喬儀
#define BLUE_GREEN SetConsoleTextAttribute(COL, 0x0003);// 羶喬儀
#define BLOOD SetConsoleTextAttribute(COL, 0x0004);		// 匐碩擎儀 
#define PURPLE SetConsoleTextAttribute(COL, 0x0005);	// 爾塭儀
#define GOLD SetConsoleTextAttribute(COL, 0x0006);		// 旎儀
#define ORIGINAL SetConsoleTextAttribute(COL, 0x0007);	// 嫩擎 �蜓� (ORIGINAL CONSOLE COLOR)
#define GRAY SetConsoleTextAttribute(COL, 0x0008);		// �蜓�
#define BLUE SetConsoleTextAttribute(COL, 0x0009);		// だ塢儀
#define HIGH_GREEN SetConsoleTextAttribute(COL, 0x000a);// 翱舒儀
#define SKY_BLUE SetConsoleTextAttribute(COL, 0x000b);	// ж棺儀
#define RED SetConsoleTextAttribute(COL, 0x000c);		// 說除儀
#define PLUM SetConsoleTextAttribute(COL, 0x000d);		// 濠輿儀
#define YELLOW SetConsoleTextAttribute(COL, 0x000e);	// 喻塢儀
#define WHITE SetConsoleTextAttribute(COL, 0x000f);		// �羃�

#define SQUARE printf("﹥");
#define SPACE printf("  ");

#define CIRCLE printf("≒"); 

int pan[36][36] = {										//Game_play()縑 噙檜朝 っ 瞪羲滲熱煎 撲薑 
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
					};									//tap 餌辨п憮 爾晦 謠啪 л.  -1: 摹鷗腎雖 彊擠, 1: 摹鷗脾. 

int pan_next[36][36] = {								//Game_play()縑憮 棻擠戲煎 夥脯還 っ 
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
					};									//tap 餌辨п憮 爾晦 謠啪 л.  -1: 摹鷗腎雖 彊擠, 1: 摹鷗脾. 

int x=0, y=0;											//⑷營 嬪纂陛 蟾晦�音Щ� 彊晦 嬪п憮 瞪羲滲熱煎 撲薑. 
int velocity=50;										//樓紫 蟾晦�音Щ� 彊晦 嬪п憮 瞪羲滲熱煎 撲薑. 

int main (void)
{
	system("mode con cols=80 lines=40");	//cols: 陛煎, lines: 撮煎, 陛煎 2蘊曖 觼晦朝 撮煎 1蘊曖 觼晦諦 翕橾
	SetConsoleTitle("Game of Life");		//console曖 title 撲薑 
	CursorFalse();							//醴憮 獗梯 
	Game_start();	//啪歜 衛濛 �飛� 碳楝螃晦 
	return 0;		//main л熱 謙猿
}

void gotoxy(int x, int y)//
{
    COORD CursorPosition = {x, y};
    SetConsoleCursorPosition(COL, CursorPosition);
}

void CursorTrue()//
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };//CONSOLE_CURSOR_INFO 掘褻羹 摹樹 
    cursorInfo.dwSize = 1;					//醴憮 舒眷 撲薑 (1~100) 
    cursorInfo.bVisible = TRUE;				//醴憮蒂 爾歜  
    SetConsoleCursorInfo(COL, &cursorInfo);
}

void CursorFalse()//
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };//CONSOLE_CURSOR_INFO 掘褻羹 摹樹 
    cursorInfo.dwSize = 1;					//醴憮 舒眷 撲薑 (1~100) 
    cursorInfo.bVisible = FALSE;			//醴憮蒂 獗梯 
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
	for(i=0;;i++)	//i蒂 1噶 隸陛衛酈賊憮 啗樓 奩犒	//Press enter to start 奩礎檜朝 擁棲詭檜暮 �膩� 
	{
        if(kbhit() and (GetAsyncKeyState(VK_RETURN))) break;	//酈殮溘檜 氈戲賊 鼠и瑞Щ 謙猿	(殮溘檜 氈棻賊 1(True), 殮溘檜 橈棻賊 0(False) 高 奩��) //棻艇 酈蒂 殮溘ж賊 梭緇檜朝 �膩�陛 橈橫螳 VK_RETURN(Enter) 酈 殮溘檜 腎橫撿 鼠и瑞Щ 謙猿煎 熱薑 
        if(i%80==0)			//i陛 80戲煎 釭援橫 雲橫韓陽 旋擊 ル衛 
		{
			gotoxy(29, 36);
			printf("Press enter to start");
		}
        else if(i%80==40)	//i曖 釭該雖陛 40橾 陽 旋擊 雖遺
		{
			gotoxy(29, 36);
			printf("                    ");
		}
        Sleep(10); //衛除 雖翱(10ms)
    }
	
	while(1)
		if((GetAsyncKeyState(VK_RETURN)))
		{
			Loading();	//雖旎梱雖 enter酈陛 揚萼 瞳檜 氈棻賊 煎註 璽 碳楝褥
			break;		//渦檜鼻 enter酈 殮溘擊 嫡雖 彊戲嘎煎 while僥 謙猿 
		}
	Game_main();	//塭檜Щ 啪歜 詭檣 �飛� 碳楝螃晦 
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
	//蟾晦 �飛� 碳楝螃晦 
	system("cls");
	
	WHITE
	gotoxy(34, 6);
	printf("Game of Life"); 
	
	RED
	gotoxy(31, 11);
	printf("忙式式式式式式式式式式式式式式式忖 ");
	gotoxy(31, 12);
	printf("弛               弛 ");
	gotoxy(31, 13);
	printf("弛      Rule     弛 ");
	gotoxy(31, 14);
	printf("弛               弛 ");
	gotoxy(31, 15);
	printf("戌式式式式式式式式式式式式式式式戎 ");
	
	WHITE
	gotoxy(31, 17);
	printf("忙式式式式式式式式式式式式式式式忖 ");
	gotoxy(31, 18);
	printf("弛               弛 ");
	gotoxy(31, 19);
	printf("弛     Sample    弛 ");
	gotoxy(31, 20);
	printf("弛               弛 ");
	gotoxy(31, 21);
	printf("戌式式式式式式式式式式式式式式式戎 ");
	
	gotoxy(31, 23);
	printf("忙式式式式式式式式式式式式式式式忖 ");
	gotoxy(31, 24);
	printf("弛               弛 ");
	gotoxy(31, 25);
	printf("弛      Play     弛 ");
	gotoxy(31, 26);
	printf("弛               弛 ");
	gotoxy(31, 27);
	printf("戌式式式式式式式式式式式式式式式戎 ");
	
	gotoxy(31, 29);
	printf("忙式式式式式式式式式式式式式式式忖 ");
	gotoxy(31, 30);
	printf("弛               弛 ");
	gotoxy(31, 31);
	printf("弛      Info     弛 ");
	gotoxy(31, 32);
	printf("弛               弛 ");
	gotoxy(31, 33);
	printf("戌式式式式式式式式式式式式式式式戎 ");
	
	gotoxy(31, 35);
	printf("key: ∟, ⊿, enter");
	gotoxy(35, 36);
	printf("restart: r");
	
	int input = getch(), i, n=1;	//⑷營 幗ぷ縑 盪濰腎橫 氈朝 enter酈 �分� 棻艇 酈蒂 嫡嬴 橈擁輿濠. 幗ぷ蒂 綠辦朝 婁薑. 
	while(1)	//鼠и 瑞Щ : 啗樓 殮溘 嫡擠 
	{
		input = getch();	//殮溘 嫡朝 л熱, ASCII囀萄煎 殮溘 嫡擠 (input檜 int⑽檜晦 陽僥) 
		if(input == 224)	//寞щ酈朝 2byte煎, 擅 旋濠曖 ASCII囀萄朝 224歜. 擅 旋濠陛 224塭賊 
							//VK_UP		(∟)	: 224 72
							//VK_LEFT	(∠)	: 224 75
							//VK_RIGHT	(⊥)	: 224 77
							//VK_DOWN	(⊿)	: 224 80
		{
			input = getch();	//菴曖 璋濠 陛螳螃晦
			if(input == 72)		//嬪 寞щ酈 殮溘 衛
			{
				n-=1;
				if(n==0) n=4;
			}
			else if(input == 80)//嬴楚 寞щ酈 殮溘 衛 
			{
				n+=1;
				if(n==5) n=1;
			}
			
			if(n==1)			//Rule擊 說除儀戲煎 
			{
				WHITE
				gotoxy(34, 6);
				printf("Game of Life"); 
				
				RED
				gotoxy(31, 11);
				printf("忙式式式式式式式式式式式式式式式忖 ");
				gotoxy(31, 12);
				printf("弛               弛 ");
				gotoxy(31, 13);
				printf("弛      Rule     弛 ");
				gotoxy(31, 14);
				printf("弛               弛 ");
				gotoxy(31, 15);
				printf("戌式式式式式式式式式式式式式式式戎 ");
				
				WHITE
				gotoxy(31, 17);
				printf("忙式式式式式式式式式式式式式式式忖 ");
				gotoxy(31, 18);
				printf("弛               弛 ");
				gotoxy(31, 19);
				printf("弛     Sample    弛 ");
				gotoxy(31, 20);
				printf("弛               弛 ");
				gotoxy(31, 21);
				printf("戌式式式式式式式式式式式式式式式戎 ");
	
				gotoxy(31, 23);
				printf("忙式式式式式式式式式式式式式式式忖 ");
				gotoxy(31, 24);
				printf("弛               弛 ");
				gotoxy(31, 25);
				printf("弛      Play     弛 ");
				gotoxy(31, 26);
				printf("弛               弛 ");
				gotoxy(31, 27);
				printf("戌式式式式式式式式式式式式式式式戎 ");
				
				gotoxy(31, 29);
				printf("忙式式式式式式式式式式式式式式式忖 ");
				gotoxy(31, 30);
				printf("弛               弛 ");
				gotoxy(31, 31);
				printf("弛      Info     弛 ");
				gotoxy(31, 32);
				printf("弛               弛 ");
				gotoxy(31, 33);
				printf("戌式式式式式式式式式式式式式式式戎 ");
			}
			else if (n==2)			//Sample擊 說除儀戲煎 
			{
				WHITE
				gotoxy(34, 6);
				printf("Game of Life"); 
				
				WHITE
				gotoxy(31, 11);
				printf("忙式式式式式式式式式式式式式式式忖 ");
				gotoxy(31, 12);
				printf("弛               弛 ");
				gotoxy(31, 13);
				printf("弛      Rule     弛 ");
				gotoxy(31, 14);
				printf("弛               弛 ");
				gotoxy(31, 15);
				printf("戌式式式式式式式式式式式式式式式戎 ");
				
				RED
				gotoxy(31, 17);
				printf("忙式式式式式式式式式式式式式式式忖 ");
				gotoxy(31, 18);
				printf("弛               弛 ");
				gotoxy(31, 19);
				printf("弛     Sample    弛 ");
				gotoxy(31, 20);
				printf("弛               弛 ");
				gotoxy(31, 21);
				printf("戌式式式式式式式式式式式式式式式戎 ");
				
				WHITE
				gotoxy(31, 23);
				printf("忙式式式式式式式式式式式式式式式忖 ");
				gotoxy(31, 24);
				printf("弛               弛 ");
				gotoxy(31, 25);
				printf("弛      Play     弛 ");
				gotoxy(31, 26);
				printf("弛               弛 ");
				gotoxy(31, 27);
				printf("戌式式式式式式式式式式式式式式式戎 ");
				
				gotoxy(31, 29);
				printf("忙式式式式式式式式式式式式式式式忖 ");
				gotoxy(31, 30);
				printf("弛               弛 ");
				gotoxy(31, 31);
				printf("弛      Info     弛 ");
				gotoxy(31, 32);
				printf("弛               弛 ");
				gotoxy(31, 33);
				printf("戌式式式式式式式式式式式式式式式戎 ");
			}
			else if (n==3)			//Play蒂 說除儀戲煎 
			{
				WHITE
				gotoxy(34, 6);
				printf("Game of Life"); 
				
				WHITE
				gotoxy(31, 11);
				printf("忙式式式式式式式式式式式式式式式忖 ");
				gotoxy(31, 12);
				printf("弛               弛 ");
				gotoxy(31, 13);
				printf("弛      Rule     弛 ");
				gotoxy(31, 14);
				printf("弛               弛 ");
				gotoxy(31, 15);
				printf("戌式式式式式式式式式式式式式式式戎 ");
				
				gotoxy(31, 17);
				printf("忙式式式式式式式式式式式式式式式忖 ");
				gotoxy(31, 18);
				printf("弛               弛 ");
				gotoxy(31, 19);
				printf("弛     Sample    弛 ");
				gotoxy(31, 20);
				printf("弛               弛 ");
				gotoxy(31, 21);
				printf("戌式式式式式式式式式式式式式式式戎 ");
				
				RED
				gotoxy(31, 23);
				printf("忙式式式式式式式式式式式式式式式忖 ");
				gotoxy(31, 24);
				printf("弛               弛 ");
				gotoxy(31, 25);
				printf("弛      Play     弛 ");
				gotoxy(31, 26);
				printf("弛               弛 ");
				gotoxy(31, 27);
				printf("戌式式式式式式式式式式式式式式式戎 ");
				
				WHITE
				gotoxy(31, 29);
				printf("忙式式式式式式式式式式式式式式式忖 ");
				gotoxy(31, 30);
				printf("弛               弛 ");
				gotoxy(31, 31);
				printf("弛      Info     弛 ");
				gotoxy(31, 32);
				printf("弛               弛 ");
				gotoxy(31, 33);
				printf("戌式式式式式式式式式式式式式式式戎 ");
			}
			
			else					//Info蒂 說除儀戲煎 
			{
				WHITE
				gotoxy(34, 6);
				printf("Game of Life");
				
				WHITE
				gotoxy(31, 11);
				printf("忙式式式式式式式式式式式式式式式忖 ");
				gotoxy(31, 12);
				printf("弛               弛 ");
				gotoxy(31, 13);
				printf("弛      Rule     弛 ");
				gotoxy(31, 14);
				printf("弛               弛 ");
				gotoxy(31, 15);
				printf("戌式式式式式式式式式式式式式式式戎 ");
				
				gotoxy(31, 17);
				printf("忙式式式式式式式式式式式式式式式忖 ");
				gotoxy(31, 18);
				printf("弛               弛 ");
				gotoxy(31, 19);
				printf("弛     Sample    弛 ");
				gotoxy(31, 20);
				printf("弛               弛 ");
				gotoxy(31, 21);
				printf("戌式式式式式式式式式式式式式式式戎 ");
	
				gotoxy(31, 23);
				printf("忙式式式式式式式式式式式式式式式忖 ");
				gotoxy(31, 24);
				printf("弛               弛 ");
				gotoxy(31, 25);
				printf("弛      Play     弛 ");
				gotoxy(31, 26);
				printf("弛               弛 ");
				gotoxy(31, 27);
				printf("戌式式式式式式式式式式式式式式式戎 ");
				
				RED
				gotoxy(31, 29);
				printf("忙式式式式式式式式式式式式式式式忖 ");
				gotoxy(31, 30);
				printf("弛               弛 ");
				gotoxy(31, 31);
				printf("弛      Info     弛 ");
				gotoxy(31, 32);
				printf("弛               弛 ");
				gotoxy(31, 33);
				printf("戌式式式式式式式式式式式式式式式戎 ");
			}
		}
		
		else if(input == 13)//VK_RETURN (Enter) : 13
		{
			//⑷營 n高縑 評塭(⑷營 碩擎儀檣 幗が縑 評塭) 蜃朝 л熱 ��轎 
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
	printf("Q: 塭檜Щ 啪歜檜 鼠歙檣陛蹂?");
	gotoxy(13, 10);
	printf("A: 艙措曖 熱з濠 襄 ��欐 夔錚檜陛 堅寰п魚 撮ん 濠翕濠");
	gotoxy(16, 11);
	printf("曖 橾謙戲煎, 陛濰 割葬 憲溥霞 撮ん 濠翕濠 陛遴等 ж");
	gotoxy(16, 12);
	printf("釭殮棲棻.");
	
	gotoxy(13, 14);
	printf("Q: 橫飩啪 Ы溯檜ж釭蹂?");
	gotoxy(13, 15);
	printf("A: ⑷營 撮渠曖 撮ん 鼻鷓蒂 夥鰻戲煎 嬴楚 舒 敘罌縑 曖п");
	gotoxy(16, 16);
	printf("棻擠 撮渠曖 撮ん 鼻鷓陛 唸薑腌棲棻.");
	
	gotoxy(14, 18);
	printf("- 避擎 撮ん曖 檜醒 醞 薑�旅� 撮 偃陛 髦嬴 氈戲賊 斜 撮");
	gotoxy(14, 19);
	printf("ん朝 髦嬴陪棻('鷓橫陪棻').");
	
	gotoxy(14, 20);
	printf("- 髦嬴 氈朝 撮ん曖 檜醒 醞縑 舒 偃釭 撮 偃陛 髦嬴 氈戲");
	gotoxy(14, 21);
	printf("賊, 斜 撮ん朝 啗樓 髦嬴 氈朝 鼻鷓蒂 嶸雖ж堅, 檜諼縑朝");
	gotoxy(14, 22);
	printf("'諼煎錶憮', 傳朝 '獗檜 虞⑵憮' 避橫幗萼棻.");
	
	gotoxy(13, 25);
	printf("Q. 橫飩啪 ж賊 檜 啪歜擊 闌望 熱 氈釭蹂?");
	gotoxy(13, 26);
	printf("A. 濠褐虜曖 塭檜Щ 啪歜 紫⑽擊 虜菟橫爾撮蹂. 營塹橫蹂.");
	
	gotoxy(13, 29);
	printf("Q. 檜蝶攪縑斜陛 襄營ж釭蹂?");
	gotoxy(13, 30);
	printf("A. 啪歜擊 號檜 Ы溯檜ж衛賊 醱碟�� 瓊戲褒 熱 氈蝗棲棻!");
	gotoxy(16, 31);
	printf("�倣昄蠅牳撚�!");
	
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
			if(input == 75)		//豭薹 寞щ酈 
			{
				if(now_pg>1) 
				{
					now_pg-=1;
					change=1;
				}
			}
			else if(input == 77)//螃艇薹 寞щ酈 
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
	printf("⊥");
	gotoxy(31, 6);
	printf("薑僭 (Still Lifes)");
	gotoxy(13, 9);
	printf("- 綰煙");
	gotoxy(17, 11);
	SQUARE
	SQUARE
	gotoxy(17, 12);
	SQUARE
	SQUARE
	gotoxy(13, 14);
	printf("- 弊餵");
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
	printf("- 誧窖檜");
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
	printf("- 爾お");
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
	printf("∠");
	gotoxy(66, 6);
	printf("⊥");
	gotoxy(30, 6);
	printf("霞翕濠 (Oscillators)");
	gotoxy(13, 9);
	printf("- 梭緇檜");
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
	printf("- 舒疏綠");
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
	printf("- 蛔渠");
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
	printf("∠");
	gotoxy(66, 6);
	printf("⊥");
	gotoxy(30, 6);
	printf("霞翕濠 (Oscillators)");
	gotoxy(13, 9);
	printf("- ぺ餌");
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
	printf("∠");
	gotoxy(66, 6);
	printf("⊥");
	gotoxy(30, 6);
	printf("辦輿摹  (Spaceships)");
	gotoxy(13, 9);
	printf("- 旋塭檜渦");
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
	printf("- 唳榆 辦輿摹 (LWSS)");
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
	printf("∠");
	gotoxy(66, 6);
	printf("⊥");
	gotoxy(31, 6);
	printf("濰熱  (Methuselah)");
	gotoxy(13, 9);
	printf("- R-も饜嘐喻");
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
	printf("- 棻檜ж萄");
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
	printf("- 紫饜葬");
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
	printf("∠");
	gotoxy(33, 6);
	printf("鼠и 撩濰 ぬ欐"); 
	gotoxy(13, 9);
	printf("- 譆模 撮ん煎 鼠и 撩濰 (10)");
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
	printf("- 譆模 賊瞳戲煎 鼠и 撩濰 (2▼12)");
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
	printf("Move: ∟, ⊿, ∠, ⊥, Select: space, Start: enter, Stop: Backspace, Reset: r");
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
			for(i=0;i<36;i++)	//っ 蟾晦�� 
			{
				for(j=0;j<36;j++)
				{
					pan[i][j]=-1;
				}
			}
			//⑷營 嬪纂 蟾晦�� 
			x=0;
			y=0;
			//撮渠 蟾晦�� 
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
			Game_main();		//詭檣 �飛� 碳楝螃晦
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
		else if(input == 32)			//VK_SP : 蝶む檜蝶 夥 
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
		
		if(input == 13)	//VK_CR: 縛攪 酈 
		{
			while(1)
			{
				if(kbhit())
				{
					playing_input = getch();
					{
						if(playing_input == 8)			//VK_BS: 寥蝶む檜蝶 
						{
							break;
						}
						else if(playing_input == 81 or playing_input == 113)	//Q: 81, q: 113
						{
							Game_main();		//詭檣 �飛� 碳楝螃晦
							break; 
						}
						else if(playing_input == 82 or playing_input == 114)	//R: 82, r: 114
						{
							for(i=0;i<36;i++)	//っ 蟾晦�� 
							{
								for(j=0;j<36;j++)
								{
									pan[i][j]=-1;
								}
							}
						//⑷營 嬪纂 蟾晦�� 
						x=0;
						y=0;
						Game_play();
						break;
						}
						else if(playing_input == 224)	//寞щ酈 
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
	printf("Made by 1203 梯貲遽, 1209 夢團營");
	
	gotoxy(13, 16);
	printf("October 19th, 2022 ~ November 11st, 2022");
	
	gotoxy(13, 19);
	printf("鬼錳婁з堅蛔з掖 1з喇 2з晦 薑爾 熱чゎ陛");
	
	gotoxy(13, 21);
	printf("鼠欽 犒薯 塽 寡ん 旎雖");
	
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
	printf("忙");
	for(i=0;i<57;i++) printf("式");
	printf("忖");
	for(i=6;i<34;i++)
	{
		gotoxy(10, i);
		printf("弛");
		for(j=0;j<57;j++) printf(" ");
		printf("弛");
	}
	gotoxy(10, 34);
	printf("戌");
	for(i=0;i<57;i++) printf("式");
	printf("戎");
}

void Egg()
{
	system("cls");
	gotoxy(4, 29);	//1203 梯貲遽 儅橾 
	printf("Egg");
	gotoxy(11, 14);	//1209 夢團營 儅橾 
	printf("Egg");
	Sleep(1000);
	Game_info();
}
