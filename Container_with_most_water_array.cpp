/* 11. Container With Most Water */ 
// Given n non-negative integers a1, a2, ..., an 
// where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line
// i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container
// contains the most water.
//Note: You may not slant the container and n is at least 2. */ 
// question link: https://leetcode.com/problems/container-with-most-water/


// Logic: first we select the widest placed heights so as to maximise our width.
// We have selected the max width. The inner placed heights can have larger capacity only if they have higher heights.
// we use this fact to reject all smaller heights.
// Now we iteratively keep updating capacity using new height and keep rejecting heights that are smaller than current heights.
int max_mater(vector<int> &height)
{
    int water = 0;
    int i = 0;
    int j = height.size() - 1;

    while(i < j)
    {
        int h = min(height[i], height[j]); // take the minimum height
        water = max(water, (j - i) * h); // find the current capacity
        while(height[i] <= h && i < j) i++; // skip heights that are less than the currently used height from left end
        while(height[j] <= h && i < j) j--; // skip heights that are less than the currently used height from right end
    }

    return water;
}