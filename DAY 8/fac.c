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


void printboard(char get[ROWS][COLS], int row, int col,int n)
{
	int i = 0;
	int j = 0;
	printf("~~~~~扫雷游戏~~~~~~\n");
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
	printf("~~~~~雷* %d ~~~~~~\n",n);

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


void Time()
{
	int h = 0;
	int m = 0;
	int s = 0;
	for (h = 0; h < 10; h++)
	{
		for (m = 0; m < 60; m++)
		{
			for (s = 0; s < 60; s++)
			{
				Sleep(990);
				system("cls");
			}
		}
	}
	
}

void judgeboard(char got[ROWS][COLS], char get[ROWS][COLS], int row, int col, int n)
{
	int a = 0;
	int b = 0;
	int i = 0;
	int j = 0;
	int input = 0;
	int count = 0;
	while (count<row*col-n)
	{
		printf("请输入排查或标记：（1 or 2)。\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入排查的坐标：（a b)。\n");
			scanf("%d %d", &a, &b);
			system("cls");
			if (get[a][b] != '1')
			{
				get[a][b] = num(got, a, b) + '0';
				if (get[a][b] == '0')
				{
					for (i = a - 1; i <= a + 1; i++)
					{
						for (j = b - 1; j <= b + 1; j++)
						{
							get[i][j] = num(got, i, j) + '0';
							count++;
						}
					}
					printboard(get, ROW, COL, n);
				}
				else
				{
					printboard(get, ROW, COL, n);
					count++;
				}
				
			}
			else if (get[a][b] == '1')
			{
				printf("很遗憾，你被炸死了。\n");
				printboard(got, ROW, COL, n);
				break;
			}
			else
			{
				printf("输入错误，请重新输入：\n");
			}
			break;
		case 2:
			printf("请输入标记的坐标：（a b)。\n");
			scanf("%d %d", &a, &b);
			system("cls");
			get[a][b] = 'x';
			n--;
			printboard(get, ROW, COL, n);
			break;
		default:
			printf("输入错误，请重新输入：\n");
			break;
		}
		
	}
	if (count == row * col - n)
	{
		printf("恭喜你，排雷成功！\n");
	}
	
}
