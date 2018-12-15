/* Find the first missing positive number */
/*Question Link: https://leetcode.com/problems/first-missing-positive */
// Given an unsorted integer array, find the smallest missing positive integer.
// Your algorithm should run in O(n) time and uses constant extra space. ** IMPORTANT CONSTRAINT **

/* MAIN POINTS */

// 1. We can use the input array to store our intermediate or modified result, so that we do not use
//    extra space as mentioned in the constrained.
// 2. The answer to this question will lie in the range 1 <= A <= N+1, where N is the size of input array.
// 3. Using the above fact, we can mark the elements present in the input in the same array itself. 
// 4. We can safely ignore all the elements that are > N as they wont be a part of the answer anyhow.

class Solution
{
    public:
    int firstMissingPositive(vector<int>& nums)
    {
        if(nums.size() < 1)
            return 1;
        int n = nums.size();

        for(int i = 0; i < n; ++i)
        {
            if(nums[i] <= 0)
                nums[i] = n + 1; // mark the non-positive entries
        }

        for(int i = 0; i < n; ++i)
        {
            if(abs(nums[i]) > n) // numbers > n will not be a part of the answer. So we can ignore them.
                continue;

            int j = abs(nums[i]) - 1;
            nums[j] = -abs(nums[j]); // Go to the index given by this value and mark its presence by using - sign.
        }

        for(int i = 0; i < n; ++i)
        {
            if(nums[i] > 0) // if any index still contains a positive value that means the index + 1 number is missing.
            return i + 1;
        }

        return n + 1;
    }
};

