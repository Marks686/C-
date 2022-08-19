#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

void menu()
{
	printf("****************************\n");
	printf("*********   1.play  ********\n");
	printf("*********   0.exit  ********\n");
	printf("****************************\n");
	printf("****************************\n");

}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };//����
	//��ʼ�����̵ĺ���
	InitBoard(board, ROW, COL);
	DispalyBoard(board, ROW, COL);//��ӡ����
	//����
	while (1)
	{
		PlayMove(board,ROW,COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DispalyBoard(board, ROW, COL);
		ComputerMove(board,ROW,COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DispalyBoard(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��");
	}
	DispalyBoard(board, ROW, COL);//��ӡ����

}
int main()
{
	srand((unsigned int)time(NULL));//������������������
	int  input = 0;
	do
	{
		menu();//��ӡ�˵�
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}