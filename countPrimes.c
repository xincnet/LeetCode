/*
NO:204
Description:
	Count the number of prime numbers less than a non-negative number, n
Hint: 
	The number n could be in the order of 100,000 to 5,000,000.
Credits:
	Special thanks to @mithmatt for adding this problem and creating all test cases.
 */
//Mon Apr 27 23:55:41 CST 2015	DEUS 
//This is very effcient and use the Method:
//http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
int countPrimes(int n) {

	if (2 >= n) return 0;

	bool* primes = (bool*)malloc(n * sizeof(bool));
	for (int i = 2; i < n; ++i)
		primes[i] = true;

	int sqr = sqrt(n - 1);
	for (int i = 2; i <= sqr; ++i)
	{
		if (primes[i])
		{
			for (int j = i * i; j < n; j += i)
				primes[j] = false;
		}
	}

	int sum = 0;
	for (int i = 2; i < n; ++i){
		sum += (primes[i]) ? 1 : 0;
	}
	free(primes);
	return sum;
}
int main()
{
	int i;
	scanf("%d", &i);
	printf("%d\n", countPrimes(i));
	return 0;
}
