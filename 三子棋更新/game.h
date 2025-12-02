#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
void menu();
void printboard(char board[ROW][COL], int row, int col);
void Iboard(char board[ROW][COL], int row, int col);
void inputboard(char board[ROW][COL],int x,int y);
void text1(char board[ROW][COL], int* x, int* y);
char iswin(char board[ROW][COL], int row, int col,char a);
void autoinput(char board[ROW][COL], int row, int col);