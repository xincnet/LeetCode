/*
NO.62
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

*/
#include <stdio.h>
#include <stdlib.h>
int uniquePaths(int m, int n) 
{
	int** nNum = (int**) malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		nNum[i] = (int*) malloc(n * sizeof(int*));
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			if (0 == i || 0 == j)
				nNum[i][j] = 1;
			else 
			{
				nNum[i][j] = nNum[i - 1][j] + nNum[i][j - 1];
			}
		}
	}
	return nNum[m -1][n -1];

}
int main()
{
	printf("%d\n", uniquePaths(5, 9));
}

