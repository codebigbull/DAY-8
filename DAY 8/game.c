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

	//��ʼ������
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');

	//printboard(mine, ROW, COL);//��ӡ����
	printboard(show, ROW, COL, EASY);//��ӡ����

	//������
	setboard(mine, ROW, COL,EASY);//�洢�׵���Ϣ��
	//printboard(mine, ROW, COL);//��ӡ����


	////����
	judgeboard(mine, show, ROW, COL, EASY);//���׵���Ϣ��
}

int main()
{
	//Time();
	int input = 0;
	srand((unsigned int)time(NULL));//�����������
	do
	{
		menu();
		printf("��ѡ�񣺣�1 or 0 ����\n");
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}