/*
   NO.121
   Say you have an array for which the ith element is the price of a given stock on day i.

   If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */
/*
   Sun May  3 20:17:56 CST 2015	DEUS
 */

int maxProfit(int* prices, int pricesSize) 
{
	int* rela = (int*) malloc(pricesSize * sizeof(int));
	for (int i = pricesSize; i > 0; i--)
	{
		if (1 != i)
		{
			rela[i - 1] = prices[i -1] - prices[i - 2];
		}
		else
			rela[i - 1] = 0;
	}
	int sum = 0;
	int max = 0;
	if (pricesSize > 1)
	{
		for (int i = 1; i < pricesSize; i++)
		{
			sum += rela[i];
			if (sum <= 0)
			{
				sum = 0;
				continue;
			}
			if (sum > max) max = sum;
		}
	}
	return max;
}
