 #define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void Initboard(char* get[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			get[i][j] = set;
		}
	}
}

void printmine(char* get[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (i == 0)
		{
			for (j = 0; j < 9; j++)
				printf("%d ",j);
		}
		else
		{
			printf("%d ",i);
			for (j = 1; j < col; j++)
			{
				printf("%s ", get[i][j]);
			}
		}
		printf("\n");
	}
}