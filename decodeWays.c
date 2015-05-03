/*
   NO.91
   A message containing letters from A-Z is being encoded to numbers using the following mapping:

   'A' -> 1
   'B' -> 2
   ...
   'Z' -> 26
   Given an encoded message containing digits, determine the total number of ways to decode it.

   For example,
   Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

   The number of ways decoding "12" is 2.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int IsMatchPreNum(char Pre, char Las)
{
	if ('1' == Pre) return 1;
	else if ('2' == Pre && Las >= '0' && Las <= '6')return 1;
	else if ('0' == Las) return -1;
	else if ('0' == Pre) return -2;
	else return 0;
}
int numDecodings(char* s) 
{
	int length = strlen(s);
	if (length > 0)
	{
		int* numArray = (int*) malloc(length * sizeof(int));

		if ('0' == s[0])return 0;
		else numArray[0] = 1;
		if (length > 1)
		{
			if (1 == IsMatchPreNum(s[0], s[1]) && '0' != s[1])numArray[1] = 2;
			else if (-1 == IsMatchPreNum(s[0], s[1]))return 0;
			else numArray[1] = 1;
		}
		for (int i = 2; i < length; i++)
		{
			if (1 == IsMatchPreNum(s[i - 1], s[i]))
			{	
				if ('0' != s[i]) numArray[i] = numArray[i - 2] + numArray[i - 1];
				else numArray[i] = numArray[i - 2];
			}
			else if (-1 == IsMatchPreNum(s[i - 1], s[i]))return 0;
			else if (-2 == IsMatchPreNum(s[i - 1], s[i]))
				numArray[i] = numArray[i - 2];
			else if (0 == IsMatchPreNum(s[i - 1], s[i]))
				numArray[i] = numArray[i - 1];
		}
		return numArray[length - 1];
	}
	else return 0;
}
int main()
{
	char* a = "11";
	printf("%d\n", numDecodings(a));
}
