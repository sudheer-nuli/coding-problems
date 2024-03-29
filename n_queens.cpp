#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#define N 5
using namespace std;
void printSolution(int board[N][N])
{
	static int k = 1;
	printf("%d-\n", k++);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf(" %d ", board[i][j]);
		printf("\n");
	}
	printf("\n");
}
bool isSafe(int board[N][N], int row, int col)
{
	int i, j;
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}
bool solveNQnext(int board[N][N], int col)
{
	if (col == N)
	{
		printSolution(board);
		return true;
	}
	bool res = false;
	for (int i = 0; i < N; i++)
	{
		if (isSafe(board, i, col))
		{
			board[i][col] = 1;
			res = solveNQnext(board, col + 1) || res;
			board[i][col] = 0;
		}
	}
	return res;
}
void solve_n_queen()
{
	int board[N][N] = { 0 };
	if (solveNQnext(board, 0) == false)
	{
		printf("Solution does not exist");
		return;
	}

	return;
}
int main()
{
	solve_n_queen();
	_getch();
	return 0;
}