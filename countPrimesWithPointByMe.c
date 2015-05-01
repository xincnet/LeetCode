/*
NO:204
Description:
	Count the number of prime numbers less than a non-negative number, n
Hint: 
	The number n could be in the order of 100,000 to 5,000,000.
Credits:
	Special thanks to @mithmatt for adding this problem and creating all test cases.
 */
#include <iostream>
#include <math.h>
using namespace std;
int countPrimes(int n)
{
	int count = 0;
	if(n > 2)
	{
		if (2 == n) return 1;
		else count++;
		struct primesArray{
			int number;
			primesArray *next;
		};

		primesArray *top = (primesArray*)malloc(sizeof(primesArray));
		top->number = 0;
		top->next = NULL;
		primesArray *cur = top;
		primesArray *end = top;
		for (int i = 3; i < n; i += 2)
		{
			for (cur = top; NULL != cur; cur = cur->next)
			{
				if(0 == cur->number)
				{
					cur->number = i;
					primesArray *tmp = (primesArray*)malloc(sizeof(primesArray));
					cur->next = tmp;
					tmp->number = 0;
					tmp->next = NULL;
					cur = tmp;
					end = tmp;
				}
				else if (0 == i % cur->number)break;
				if (cur->number > sqrt(i)){
					
					end->number = i;
					primesArray *tmp = (primesArray*)malloc(sizeof(primesArray));
					end->next = tmp;
					tmp->number = 0;
					tmp->next = NULL;
					cur = tmp;
					end = tmp;
				}
			}
		}
		for (cur = top; NULL != cur; )
		{
			if(0 != cur->number)
			{
				primesArray *tmp;
				tmp = cur;
				cur = cur->next;
				free(tmp);
				count++;
			}
			else
			{
				free(cur);
				cur = NULL;
			}
		}
	}
	return count;
}
int main(){
	int i;
	cin >> i;
	cout << countPrimes(i) << endl;
}
