 #define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void Initboard(char get[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			get[i][j] = set;
		}
	}
}


void printboard(char get[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("~~~~~É¨À×ÓÎÏ·~~~~~~\n");
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			if (i == 0)
			{
				printf("%d ", j);
			}
			else
			{
				printf("%c ", get[i][j]);
			}

		}
		printf("\n");
	}
	printf("~~~~~É¨À×ÓÎÏ·~~~~~~\n");

}

void setboard(char get[ROWS][COLS], int row, int col, int n)
{
	int a = 0;
	int b = 0;
	while (n > 0)
	{
		a = rand() % 9 + 1;
		b = rand() % 9 + 1;
		if (get[a][b] != '1')
		{
			get[a][b] = '1';
			n--;
		}
	}
}

int  num(char got[ROWS][COLS], int x, int y)
{
	return got[x - 1][y - 1] +
		got[x - 1][y] +
		got[x - 1][y + 1] +
		got[x][y - 1] +
		got[x][y + 1] +
		got[x + 1][y - 1] +
		got[x + 1][y] +
		got[x + 1][y + 1] - 8 * '0';
}


void judgeboard(char got[ROWS][COLS], char get[ROWS][COLS], int row, int col, int n)
{
	int a = 0;
	int b = 0;
	int count = 0;
	while (count<row*col-n)
	{
		printf("ÇëÊäÈëÅÅ²éµÄ×ø±ê£º£¨a b)¡£");
		scanf("%d %d", &a, &b);
		if (get[a][b] != '1')
		{
			get[a][b] = num(got, a, b) + '0';
			printboard(get, ROW, COL);
			count++;
		}
		else if (get[a][b] == '1')
		{
			printf("ºÜÒÅº¶£¬Äã±»Õ¨ËÀÁË¡£\n");
			printboard(got, ROW, COL);
			break;
		}
		else
		{
			printf("ÊäÈë´íÎó£¬ÇëÖØÐÂÊäÈë£º");
		}
	}
	if (count == row * col - n)
	{
		printf("¹§Ï²Äã£¬ÅÅÀ×³É¹¦£¡\n");
	}
	
}
