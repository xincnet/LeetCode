/*
NO.32
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestValidParentheses(char* s) 
{
	int length = strlen(s);
	int* dp = (int*) malloc(length * sizeof(int));
	memset(dp, 0, length * sizeof(int));
	int nMax = 0;
	for (int i = 1; i < length; i++)
	{
		if ('(' == s[i]) dp[i] = 0;
		else
		{
			if ('(' == s[i - 1])
			{
				dp[i] = i - 2 > 0 ? dp[i - 2] + 2 : 2;
				nMax = nMax > dp[i] ? nMax : dp[i];
			}
			else if (i - dp[i - 1] - 1 >= 0 &&'(' == s[i - dp[i - 1] - 1]) 
			{
				dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
				nMax = nMax > dp[i] ? nMax : dp[i];
			}
		}
	}
	return nMax;
}
int main()
{
	char test[] = "()(()";
	printf("%d\n", longestValidParentheses(test));
}

