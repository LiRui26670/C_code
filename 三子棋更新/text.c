#include"game.h"
int main()
{
	srand((unsigned int)time(NULL));
	int sign = 1;
	do {
		//菜单
	menu();
	int input = 0,select = 1;
	int x = 0, y = 0;
	char result;
	
		scanf_s("%d", &input);
		switch (input)
		{
		case 1: 
		{
			//棋盘初始
			char board[ROW][COL] = { 0 };
			Iboard(board,ROW,COL);
			//棋盘
			printboard(board,ROW,COL);
			do {
				//玩家输入//判断合法性
				inputboard(board, x, y);
				printboard(board, ROW, COL);
				//判断输赢
				result = iswin(board, ROW, COL, '*');
				if (result == 'R')
				{
					printf("恭喜，你赢了！\n");
					select = 0;
					break;
				}
				else if (result == 'D')
				{
					printf("遗憾，你输了！\n");
					select = 0;
					break;
				}
				else if (result == 'P')
				{
					printf("平局！\n");
					select = 0;
					break;
				}
				//棋盘
				//电脑输入//判断合法性
				autoinput(board,ROW,COL);
				printboard(board, ROW, COL);
				//判断输赢
				result = iswin(board, ROW, COL, '#');
				//循环
				if (result == 'R')
				{
					printf("恭喜，你赢了！\n");
					select = 0;
				}
				else if (result == 'D')
				{
					printf("遗憾，你输了！\n");
					select = 0;
				}
				else if (result == 'P')
				{
					printf("平局！\n");
					select = 0;
				}
				
			} while (select);
		} break;
		case 0: {
			printf("游戏结束！\n");
			sign = 0;
		} break;
		default: {
			printf("输入不合法，请重新输入！\n");
		}
		}
	} while (sign);
	return 0;
}