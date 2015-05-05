/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define min(a, b) (a < b ? a : b)
int minDistance(char* word1, char* word2) 
{
	int lenW1 = strlen(word1);
	int lenW2 = strlen(word2);

	int** dp = (int**) malloc((lenW1 + 1) * sizeof(int*));
	for (int i = 0; i < (lenW1 + 1); i++) dp[i] = (int*) malloc((lenW2 + 1) * sizeof(int));
	
	for (int i = 0; i < (lenW1 + 1); i++)
	{
		for (int j = 0; j < (lenW2 + 1); j++)
		{
			if (0 == i && 0 == j) dp[i][j] = 0;
			else if (0 == i) dp[i][j] = dp[i][j - 1] + 1;
			else if (0 == j) dp[i][j] = dp[i - 1][j] + 1;
			else if 
			(word1[i - 1] == word2[j - 1] && dp[i - 1][j - 1] == min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]))
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
			else 
			{
			dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			}
		}
	}

	return dp[lenW1][lenW2];
}
int main()
{
	char w1[] = "aa";
	char w2[] = "a";
	printf("%d\n", minDistance(w1, w2));
}
