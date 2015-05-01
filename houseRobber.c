/*
   NO.198
   You are a professional robber planning to rob houses along a street. 
   Each house has a certain amount of money stashed the only constraint stopping you from robbing each of them is that adjacent houses have security system connected 
   and it will automatically contact the police if two adjacent houses were broken into on the same night.

   Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
 */
int rob(int* nums, int numsSize)
{
	if (1 == numsSize) return nums[0];
	else if (2 == numsSize) return nums[0] > nums[1] ? nums[0] : nums[1];
	else if (3 == numsSize) return nums[0] + nums[2] > nums [1] ? nums[0] + nums[2] : nums[1];
	else  
	{
		int F = nums[0] + rob((nums + 2), numsSize -2);
		int L = rob((nums + 1), numsSize - 1);
		return F > L ? F : L;
	}
}
int main()
{
	int a[100] = {114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240};
	printf("YU::%d\n", rob(a, 40));
}
