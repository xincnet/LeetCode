/*
   NO.215
   Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

   For example,
   Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
 */

#include "heap.h"
int findKthLargest(int* nums, int numsSize, int k) 
{
	int F = numsSize - k + 1;	//Notice: Get the Kth Largest.
	if (!nums || numsSize < 1 || F < 1 || F > numsSize) return 0x7FFFFFFF;

	PriorityQueue H = initialize(F);
	insert(nums[0], H);
	for (int i = 1; i < numsSize; i++)
	{
		if (!isFull(H)) insert(nums[i], H);
		else if(H->elements[1] >= nums[i])
		{
			deleteMax(H);
			insert(nums[i], H);
		}
	}
	return H->elements[1];
}

int main()
{
	int a[4] = {2, 1, 8 ,9 };
	printf("			%d\n", findKthLargest(a, 4, 3));
	return 0;
}
