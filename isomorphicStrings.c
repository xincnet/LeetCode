/*
   NO.205
   Given two strings s and t, determine if they are isomorphic.

   Two strings are isomorphic if the characters in s can be replaced to get t.

   All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

   For example,
   Given "egg", "add", return true.

   Given "foo", "bar", return false.

   Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
 */
#include <stdio.h>

bool isIsomorphic(char* s, char* t) 
{
	char sArray[256] = {0};
	char tArray[256] = {0};
	int i = 0;
	while (s[i] && t[i])
	{
		if (!sArray[s[i]] && !tArray[t[i]])
		{
			sArray[s[i]] = t[i];
			tArray[t[i]] = s[i];
		}
		else if (sArray[s[i]] != t[i] || tArray[t[i]] != s[i])
			return false;
		i++;
	}
	return true;
}



