/* Jump Game */
/*Question Link: https://leetcode.com/problems/jump-game */

/*  
    Given an array of non-negative integers, you are initially positioned at the first index of the array.
    Each element in the array represents your maximum jump length at that position.
    Determine if you are able to reach the last index.
*/

/* There can be two approaches: greedy and DP. Here the greedy approach is given */

class Solution 
{
    public:
     
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        int nearest = n - 1; // initialize a GOOD point which is reachable from last index.(We can reach last index from itself                                 trivially)

        for(int  i = n - 2; i >= 1; --i) // iterate from right side and keep updating the nearest reachable GOOD point.
        {
            if(i + nums[i] >= nearest)
                nearest = i;

        }

        return nums[0] >= nearest; // return TRUE if the nearest GOOD point is reachable from 0th index else return FALSE.
                                                                                             
    }
};
