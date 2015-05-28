/*
   NO.123
   Say you have an array for which the ith element is the price of a given stock on day i.

   Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define max(a, b) (a > b ? a : b)
int maxProfit(int k, int* prices, int pricesSize) 
{
	if (pricesSize < 2) return 0;
	int maxProfit = 0;
	if (k >= (pricesSize / 2)) 
	{
		for (int i = 1; i < pricesSize; i++)
		{
//			printf("I:%dR:%d		", i, (prices[i] - prices[i - 1]));
			maxProfit += max(0, prices[i] - prices[i - 1]);
		}
		return maxProfit;
	}
//	printf("++++++++++++");
	int* dp = (int*) malloc((pricesSize) * sizeof(int));
	memset(dp, 0, (pricesSize) * sizeof(int));

	int runningProfit = 0;
	int currentProfit = 0;
	int prevMaxProfit = 0;
	for (int i = 0; i < k; i++)
	{
//	printf("I:%d\n", i);
		prevMaxProfit = dp[i];
		runningProfit = 0;
//	printf("prevMaxProfit:%d	runningProfit:%d\n", prevMaxProfit, runningProfit);
		for (int j = 1; j < pricesSize; j++)
		{
			currentProfit = prices[j] - prices[j - 1];
		//	printf("%d	", currentProfit);
			runningProfit = max((runningProfit + currentProfit), prevMaxProfit);
//			printf("%d,", runningProfit);
			prevMaxProfit = dp[j];
	//		printf("%d	", prevMaxProfit);
			dp[j] = max(runningProfit, dp[j - 1]);
			printf("%d	", dp[j]);
		}
		printf("\n");
	}
	return dp[pricesSize - 1];
}
int main()
{
	int a[] = {1,0,1,2,-1,1,6,2,5};
	printf("\n%d\n", maxProfit(3, a, 9));
}
