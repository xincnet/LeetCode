/*
NO.123
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
int maxProfit(int* prices, int pricesSize) 
{
	int sumPlus = 0;
	int sumMinus = 0;
	int sumMax = 0;
	int sumMin = 0;
	int Max = 0;
	for (int i = 1; i < pricesSize; i++)
	{
		int flu = prices[i] - prices[i - 1];
		sumPlus += flu;
		sumMinus += flu;
		if (sumPlus <= 0)
		{
			sumPlus = 0;
			sumMinus = 0;
			continue;
		}
		if (sumMinus >= 0) sumMinus = 0;

		if (sumPlus > sumMax) sumMax = sumPlus;
		if (sumMin < sumMinus) sumMin = sumMinus;
		if (Max < (sumMax - sumMin)) Max = (sumMax - sumMin);
	}
	return Max;
}
int main()
{
	int a[] = {2,1,2,0,1};
	printf("%d\n", maxProfit(a, 5));
}
