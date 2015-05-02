/*
   NO.198
   You are a professional robber planning to rob houses along a street. 
   Each house has a certain amount of money stashed the only constraint stopping you from robbing each of them is that adjacent houses have security system connected 
   and it will automatically contact the police if two adjacent houses were broken into on the same night.

   Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
 */
 #include <stdio.h>
int rob(int* nums, int numsSize)
{
	int *re = (int*) malloc(numsSize * sizeof(int));
	for (int i = 0; i < numsSize; i++)
	{
		re[i] = -1;
	}
	return robMemorized(nums, 0, numsSize, re);
}
int robMemorized(int* nums, int start, int numsSize, int* re)
{
	if (-1 != re[start]) return re[start];
	else if (start == numsSize - 1) 
	{	
		re[start] = nums[start];
		return re[start];
	}
	else if (start == numsSize - 2) 
	{
		re[start] = nums[start] > nums[start + 1] ? nums[start] : nums[start + 1];
		return re[start];
	}
	else if (start == numsSize - 3) 
	{
		re[start] = nums[start] + nums[start + 2] > nums [start + 1] ? nums[start] + nums[start + 2] : nums[start + 1];
		return re[start];
	}
	else  
	{
		int F = nums[start] + robMemorized(nums, start + 2, numsSize, re);
		int L = robMemorized(nums, start + 1, numsSize, re);
		re[start] = F > L ? F : L;
		return re[start];
	}
}




int main()
{
	int a[100] = {114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240};
	printf("YU::%d\n", rob(a, 100));
}
