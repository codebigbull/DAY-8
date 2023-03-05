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

	printmine(mine, ROW, COL);//打印数组
	printmine(show, ROW, COL);//打印数组

	//布置雷
	setBoard(mine, ROW, COL,n);//存储雷的信息。

	////排雷
	//Boardshow(show[ROWS][COLS], ROW, COL,n);//排雷的信息。

	////判断


	////打印棋盘
	//printmine(mine[ROWS][COLS], ROW, COL);//打印数组
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//生成随机数。
	do
	{
		menu();
		printf("请选择：（1 or 0 ）。\n");
		scanf("%d", &input);
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