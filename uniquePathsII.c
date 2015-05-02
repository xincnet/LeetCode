/*
   NO.63
   Follow up for "Unique Paths":

   Now consider if some obstacles are added to the grids. How many unique paths would there be?

   An obstacle and empty space is marked as 1 and 0 respectively in the grid.

   For example,
   There is one obstacle in the middle of a 3x3 grid as illustrated below.
   [
   [0,0,0],
   [0,1,0],
   [0,0,0]
   ] 
   The total number of unique paths is 2.

Note: m and n will be at most 100.
 */
#include <stdlib.h>
#include <stdio.h>
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize)
{
	int** nNum = (int**) malloc(obstacleGridRowSize * sizeof(int*));
	for (int i = 0; i < obstacleGridRowSize; i++)
	{
		nNum[i] = (int*) malloc(obstacleGridColSize * sizeof(int));
	}

	int flagCol = 0;
	int flagRow = 0;
	for (int i = 0; i < obstacleGridRowSize; i++)
	{
	
		for (int j = 0; j < obstacleGridColSize; j++)
		{
			if (1 == obstacleGrid[i][j])
			{
				nNum[i][j] = -1;
				if (0 == i) flagRow = 1;
				if (0 == j) flagCol = 1;
				if (0 == i && 0 == j)
				{
					flagCol = 1;
					flagRow = 1;
				}
			}
			else if (0 == i || 0 == j)
			{
				if (0 == i)
				{
					if (0 == flagRow) nNum[i][j] = 1;
					else nNum[i][j] = 0;
				}
				else if (0 == j)
				{
					if (0 == flagCol) nNum[i][j] = 1;
					else nNum[i][j] = 0;
				}
			}
			else
			{
				if (-1 == nNum[i - 1][j - 1] && -1 == nNum[i][j - 1])
					nNum[i][j] = 0;
				else if (-1 == nNum[i - 1][j])
					nNum[i][j] = nNum[i][j - 1];
				else if (-1 == nNum[i][j - 1])
					nNum[i][j] = nNum[i - 1][j];
				else
					nNum[i][j] = nNum[i - 1][j] + nNum[i][j - 1];

			}

		}
	}
	if (-1 == nNum[obstacleGridRowSize -1][obstacleGridColSize -1])
		return 0;
	else
		return nNum[obstacleGridRowSize -1][obstacleGridColSize -1];
}
int main()
{
	int row = 3;
	int col = 3;
	int** grid = (int**) malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++)
		grid[i] = (int*) malloc(col * sizeof(int));
	grid[0][0] = 0;
	grid[0][1] = 0;
	grid[0][2] = 0;
	grid[1][0] = 0;
	grid[1][1] = 1;
	grid[1][2] = 0;
	grid[2][0] = 0;
	grid[2][1] = 0;
	grid[2][2] = 0;
	//printf("START::\n");
	printf("%d\n", uniquePathsWithObstacles(grid, row, col));
}
