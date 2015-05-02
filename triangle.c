/*
   NO.120
   Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

   For example, given the following triangle
   [
   [2],
   [3,4],
   [6,5,7],
   [4,1,8,3]
   ]
   The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */
#include <stdlib.h>
#include <stdio.h>
int minimumTotal(int **triangle, int numRows) 
{
	int** dpTri = (int**) malloc(numRows * sizeof(int*));
	for (int i = 0; i < numRows; i++)
	{
		dpTri[i] = (int*) malloc(numRows * sizeof(int));
	}
	
	for (int i = numRows - 1; i >= 0; i--)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (numRows - 1 == i)
			{
				dpTri[i][j] = triangle[i][j];
			}
			else
			{
				int L = triangle[i][j] + dpTri[i + 1][j];
				int R = triangle[i][j] + dpTri[i + 1][j + 1];
				dpTri[i][j] = L < R ? L : R;
			}
		}
	}
	int re = dpTri[0][0];
	free(dpTri);
	return re;
}
int main()
{
	int scale = 3;
	int** a = (int**) malloc(scale * sizeof(int*));
	for (int i = 0; i < scale; i++)
	{
		a[i] = (int*) malloc(scale * sizeof(int));
	}
	a[0][0] = -10;
	a[0][1] = 2;
	a[0][2] = 3;
	a[1][0] = 4;
	a[1][1] = 5;
	a[1][2] = 6;
	a[2][0] = 7;
	a[2][1] = 8;
	a[2][2] = 9;
	printf("%d\n", minimumTotal(a, 3));
	free(a);	
}

