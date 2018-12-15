/* Longest Substring Without Repeating Characters */
/* An important question which covers the sliding window concept */
/* Constraint: try it in O(n) */
/* Given a string, find the length of the longest substring without repeating characters. */
/* Question Link: https://leetcode.com/problems/longest-substring-without-repeating-characters */

/* The idea is to maintain a variable which holds the starting point of the current window. We also maintain a dictionary of 256
 * items (we have 256 chars in ASCII), where we store the latest position of the current character while traversing the input 
 * string. As soon as we see that we have seen current character before, we change the starting point of the wondow to the 
 * immediate next position of the stored position. Also, we keep on updating the max length of the answer.
 */

 /* Code */

 int lengthOfLongestSubstring(string s)
 {
    int len = s.length();
    if(len == 0)
        return 0;

    if(len == 1)
        return 1;

    int _max = 0; // stores the answer
    int start = -1; // stores the starting point of the sliding window
    int dict[256];
    memset(dict, -1, sizeof(dict)); // stores the last seen index of a character in the input string

    for(int i = 0; i < len; ++i)
    {
        int index = s[i];
        int val = dict[index];
        if(val > start) // check if this char has been seen before in the current window.
            start = val; // change the window starting point to the immediate next point.
        dict[index] = i; // store the latest seen position of this character.
        _max = max(_max, i - start); // update answer, "i - start" gives current window size.
    }

    return _max;

 }
