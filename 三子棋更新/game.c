#include"game.h"
void menu()
{
	printf("*********************************\n");
	printf("*********1.开始  0.退出**********\n");
	printf("*********************************\n");
	printf("你的选择：");
}
void printboard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf(" %c ",board[i][j]);
			if(j<COL-1)
				printf("|");
		}
		printf("\n");
		if (i < ROW - 1)
			printf("-----------\n");
	}
}
void Iboard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void inputboard(char board[ROW][COL], int x, int y)
{
	int sign = 0;
	do {
		sign = 0;
		do {
			sign = 0;
			printf("请输入落子坐标：");
			scanf_s("%d %d", &x, &y);
			if (x > 0 && x <= ROW && y > 0 && y <= COL)
				;
			else
			{
				printf("输入不合法，请重新输入！\n");
				sign = 1;
			}
		} while (sign);
		if (board[x - 1][y - 1] != '*')
			//board[x - 1][y - 1] = '*';
			;
		else
		{
			printf("该位置已有棋子，请重新输入！\n");
			sign = 1;
		}
		board[x - 1][y - 1] = '*';
	} while (sign);
}
char iswin(char board[ROW][COL], int row, int col,char a)
{
	int i = 0, j = 0,sum = 0;
	for (i = 0; i < ROW; i++)//行
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == a)
				sum++;
			else
				break;
		}
		if (sum == 3)
		{
			return 'R';
		}
		sum = 0;
	}
	i = 0, j = 0, sum = 0;
	for (j = 0; j < COL; j++)//列
	{
		for (i = 0; i < ROW; i++)
		{
			if (board[i][j] == a)
				sum++;
			else
				break;
		}
		if (sum == 3)
		{
			return 'R';
		}
		sum = 0;
	}
	i = 0, j = 0, sum = 0;
	for (i = 0, j = 0; i < ROW, j < COL; i++, j++)//左向右对角
	{
		if (board[i][j] == a)
			sum++;
		else
			break;
	}
	if (sum == 3)
	{
		return 'R';
	}
	i = 0, j = 0, sum = 0;
	for (i = 0, j = COL-1; i < ROW, j >= 0; i++, j--)//右向左对角
	{
		if (board[i][j] == a)
			sum++;
		else
			break;
	}
	if (sum == 3)
	{
		return 'R';
	}
	i = 0, j = 0, sum = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
				return 'C';
			else
				sum++;
		}
	}
	if (sum == ROW * COL)
		return 'P';
}
void autoinput(char board[ROW][COL],int row,int col)
{
	int sign = 0,x = 0,y = 0;
	printf("电脑输入：\n");
	do {
		int x = rand() % row; int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			sign = 0;
		}
		else
			sign = 1;
	} while (sign);	
}