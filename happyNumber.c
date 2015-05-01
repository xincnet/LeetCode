/*
	NO.202
	Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: 
	
	Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. 
	Those numbers for which this process ends in 1 are happy numbers.

	Example: 19 is a happy number

	1^2 + 9^2 = 82
	8^2 + 2^2 = 68
	6^2 + 8^2 = 100
	1^2 + 0^2 + 0^2 = 1

Credits:
	Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.
 */
 
/*
*	Tue Apr 28 13:12:13 CST 2015	DEUS
*	If n is not happy, then its sequence does not go to 1. Instead, it ends in the cycle:
*	4, 16, 37, 58, 89, 145, 42, 20, 4, ...
*	Reference:http://en.wikipedia.org/wiki/Happy_number
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX 10
bool isHappy(int n) 
{
	int Flag = 0;
	int nTmp = n;
	do 
	{
		int digArray[MAX] = {0};
		for (int i = 0; 0 != nTmp; i++)
		{
			digArray[i] = nTmp % 10;
			nTmp /= 10;
		}
		int sum = 0;
		for (int j = 0; j < MAX; j++)
		{
			sum += digArray[j] * digArray[j];
		}
		nTmp = sum;
		if (4 == sum) return false;
	}
	while (1 != nTmp);

	return true;


}

int main()
{
	int i;
	scanf("%d", &i);
	for (int j = 2; j < i; j++)
	{
	if (isHappy(j))
		printf("%d\n", j);
	}
}
