/*
   NO.64
   Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
 */
/*
   Sat May  2 22:57:08 CST 2015	DEUS
 */
#include <stdlib.h>
#include <stdio.h>
int minPathSum(int** grid, int gridRowSize, int gridColSize)
{
	int** minGrid = (int**) malloc(gridRowSize * sizeof(int*));
	for (int i = 0; i < gridRowSize; i++)
	{
		minGrid[i] = (int*) malloc(gridColSize * sizeof(int));
	}

	minGrid[0][0] = grid[0][0];
	for (int i = 0; i < gridRowSize; i++)
	{
		for (int j = 0; j < gridColSize; j++)
		{
			if (0 == i && 0 != j)
				minGrid[i][j] = minGrid[i][j - 1] + grid[i][j];
			else if (0 != i && 0 == j)
				minGrid[i][j] = minGrid[i - 1][j] + grid[i][j];
			else if (0 < i && 0 < j)
			{
				minGrid[i][j] = grid[i][j] + (minGrid[i][j - 1] < minGrid[i - 1][j] ? minGrid[i][j - 1] : minGrid[i - 1][j]);
			}
		}
	}
	return minGrid[gridRowSize - 1][gridColSize - 1];
}   

int main()
{
	int scale = 3;
	int** a = (int**) malloc(scale * sizeof(int*));
	for (int i = 0; i < scale; i++)
	{
		a[i] = (int*) malloc(scale * sizeof(int));
	}
	a[0][0] = 1;
	a[0][1] = 3;
	a[0][2] = 1;
	a[1][0] = 1;
	a[1][1] = 5;
	a[1][2] = 1;
	a[2][0] = 4;
	a[2][1] = 2;
	a[2][2] = 1;
	printf("%d\n", minPathSum(a, 3, 3));
	free(a);	
}
