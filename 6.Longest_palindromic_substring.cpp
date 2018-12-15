/* Longest Palindromic substring */
/*Question Link: leetcode.com/problems/longest-palindromic-substring/submissions */
/* The basic idea is to consider every character as a centre element and then expand the palindrome on both sides */

Class Solution {
public:
    string longestPalindrome(string s) {
    int len = s.length();
    int max_len = 0;
    int start = -1;
    
    for(int i = 0; i < len; ++i)
    {
        int left = i, right = i;
        while(s[++right] == s[left]) // skip duplicate elements (an important step)
        {
            ++right;
            ++i;
        }

        while(left - 1 >= 0 && right + 1 < len && s[left - 1] == s[right + 1]) // expand the palindrome on both sides
        {
            --left;
            ++right;
        }

        if(right - left + 1 > max_len) // update the length of palindromic substring found so far
        {
            max_len = right - left + 1;
            start = left;
        }
        
        return s.substr(left, max_len);
    
    }
