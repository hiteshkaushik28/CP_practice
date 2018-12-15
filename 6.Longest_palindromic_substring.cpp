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

/* Another nice solution using DP */
Class Solution{
public:
    string longestPalindrome(string s){
    int len = s.length();
    if(len < 2)
        return s;
    int start = 0;
    int max_len = 1;
    int dp[len][len]; // to store if some part of the current substring is also palindrome
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i < len; ++i)
    {
        dp[i][i] = 1; // all single characters are palindromes
        if(i + 1 < len && s[i] == s[i + 1]) // marking all 2 adjacement same characters
        {
            dp[i][i + 1] = 1;
            start = i;
            max_len = 2;
        }
    }

    for(int k = 3; k <= len; ++k) // this loop is for length of palindrome. Since we marked for length 2 above, k:from 3 to len.
    {
        for(int i = 0; i < n-k+1; ++i) // this loop iterates over the input string.
        {
            int j = i + k - 1; // we get the ending index of the substring that starts from i and spans till i+k characters.

            if(dp[i+1][j-1] && s[i] == s[j]) // here we use precomputed results to check if substring of this string is already
                                            //seen as palindrome or not
            {
                dp[i][j] = 1;
                start = i;

                max_len = max(max_len, k); // we keep updating the max length seen so far
            }
        }
    }

    return s.substr(start, max_len);
    }
};      
