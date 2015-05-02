/*
   NO.70
   You are climbing a stair case. It takes n steps to reach to the top.

   Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */
#include <stdlib.h>
#include <stdio.h>

int climbStairs(int n) 	
{
	if (n > 0)
	{
		int* step = (int*) malloc((n + 1) * sizeof(int));
		step[0] = 1;
		step[1] = 1;
		for (int i = 2; i <= n; i ++)
		{
			step[i] = step[i - 1] + step[i - 2];
		}
		return step[n];
	}
	else return -1;
}

int main()
{
	int i;
	scanf("%d", &i);
	printf("%d\n", climbStairs(i));
}
