/*
   NO.97
   Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

   For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
bool isInterleave(char* s1, char* s2, char* s3) 
{
	int lenS1 = strlen(s1);
	int lenS2 = strlen(s2);
	int lenS3 = strlen(s3);
	if (lenS3 != lenS1 + lenS2) return 0;
	int** dp = (int**) malloc((lenS1 + 1) * sizeof(int*));
	for (int i = 0; i < lenS1 + 1; i++)
	{
		dp[i] = (int*) malloc((lenS2 + 1) * sizeof(int));
		memset(dp[i], 0, (lenS2 + 1) * sizeof(int));
	}
	for (int i = 0; i < lenS1 + 1; i++)
	{
		for (int j = 0; j < lenS2 + 1; j++)
		{
			if (0 == i && 0 == j) dp[i][j] = 1;
			else if (0 == i) dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			else if (0 == j) dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
			else 
				dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]); 
		}
	}
	int re = dp[lenS1][lenS2];
	for (int i = 0; i < lenS1; i++) free(dp[i]);
	free(dp);
	return re;
}
int main()
{
	char s1[] = "aabcc";
	char s2[] = "dbbca";
	char s3[] = "aadbbbaccc";
	printf("%d\n", isInterleave(s1, s2, s3));
}
