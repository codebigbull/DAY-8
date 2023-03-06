 #define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void menu()
{
	printf("*********************\n");
	printf("******1. play********\n");
	printf("******0. exit********\n");
	printf("*********************\n");
}

game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//初始化棋盘
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');

	//printboard(mine, ROW, COL);//打印数组
	printboard(show, ROW, COL, EASY);//打印数组

	//布置雷
	setboard(mine, ROW, COL,EASY);//存储雷的信息。
	//printboard(mine, ROW, COL);//打印数组


	////排雷
	judgeboard(mine, show, ROW, COL, EASY);//排雷的信息。
}

int main()
{
	//Time();
	int input = 0;
	srand((unsigned int)time(NULL));//生成随机数。
	do
	{
		menu();
		printf("请选择：（1 or 0 ）。\n");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏。");
			break;
		default:
			printf("选择错误！请重新选择：\n");
			break;
		}
	} while (input);
	return 0;
}