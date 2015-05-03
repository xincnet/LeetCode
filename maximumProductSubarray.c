/*
   NO.152
   Find the contiguous subarray within an array (containing at least one number) which has the largest product.

   For example, given the array [2,3,-2,4],
   the contiguous subarray [2,3] has the largest product = 6.
 */
/*
   Sun May  3 14:19:28 CST 2015	DEUS
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int maxProduct(int* nums, int numsSize) 
{
	int** re = (int**) malloc(numsSize * sizeof(int*));
	for (int i = 0; i < numsSize; i++)re[i] = (int*) malloc(2 * sizeof(int));

	int minus = -1;
	int mFlag = 0;

	int sum = 1;
	int max = nums[0];
	for (int i = 0; i < numsSize; i++)
	{
		sum *= nums[i];
		re[i][0] = sum;
		if (sum < 0)
		{
			if (0 == mFlag)
			{
				minus = i;
				mFlag = 1;
				re[i][1] = -2;
			}
			else re[i][1] = minus;
		}
		else re[i][1] = -1;
		if (abs(sum) < 1)
		{
			sum = 1;
			mFlag = 0;
		}
		else if (abs(sum) > abs(max))max = sum;
	}
	max = re[0][0];
	for (int i = 0; i < numsSize; i++)
	{
		if (re[i][1] >= 0)
		{
			re[i][0] /= re[re[i][1]][0];
		}
		if (re[i][0] > max) max = re[i][0];

	}
	return max;
}
int main()
{
	int num = 10;
	int* input = (int*) malloc(num * sizeof(int));

	srand((unsigned) time(NULL)); 

	for (int i = 0; i < num; i++)
	{
		input[i] = rand() % 20 - 10;  
		printf("%d	", input[i]);
	}
	printf("\n");
	printf("::%d\n", maxProduct(input, num));
}
