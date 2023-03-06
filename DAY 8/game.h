 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY 10

void Initboard(char get[ROWS][COLS], int row, int col, char set);

void printboard(char get[ROWS][COLS], int row, int col, int n);

void setboard(char get[ROWS][COLS], int row, int col, int n);

void judgeboard(char got[ROWS][COLS], char get[ROWS][COLS], int row, int col, int n);
int num(char got[ROWS][COLS], int x, int y);//计算附近雷数量。

void Time();//计时器


