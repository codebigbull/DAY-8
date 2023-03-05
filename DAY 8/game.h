 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

void Initboard(char* get[ROWS][COLS], int row, int col, char set);

void printmine(char* get[ROWS][COLS], int row, int col);//´òÓ¡Êý×é

