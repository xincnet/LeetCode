/*
NO.115
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numDistinct(char* s, char* t) 
{
	int lenS = strlen(s);
	int lenT = strlen(t);

	int** dp = (int**) malloc((lenT + 1) * sizeof(int*));
	for (int i = 0; i < (lenT + 1); i++) dp[i] = (int*) malloc((lenS + 1) * sizeof(int));

	for (int i = 0; i < (lenT + 1); i++)
	{
		for (int j = 0; j < (lenS + 1); j++)
		{
			if (0 == i) dp[i][j] = 1;
			else if (i > j) dp[i][j] = 0;
			else if (s[j - 1] == t[i - 1]) dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
			else dp[i][j] = dp[i][j] = dp[i][j - 1];
		}
	}
	
	int re = dp[lenT][lenS];
	for(int i = 0; i < (lenT + 1); i++) free(dp[i]);
	free(dp);
	return re;
}
int main()
{
	char S[] = "ccc";
	char T[] = "c";
	printf("%d\n", numDistinct(S, T));
}
