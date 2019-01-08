/* Count Distinct Subsequences
 * Given a string, find the count of distinct subsequences of it.
 * Approach 1: This problem is same as finding all distinct subsets. Using bitmasking, this can be done in O(n*2^n).
 * Approach 2: Suppose we know that n is the count of subsequences after using first i characters.Then if we append (i+1)th char
 * to all the n sequences, we will get all the sequences after using first (i+1)th characters. This corresponds to optimal 
 * substructure and overlapping subproblems , so we can happily go with DP.
 * Let count(n) be the count using first n chars. Then count(n) = 2*count(n-1) - repetitions.
 * The main part is finding the repetitions. We will store the last seen index of each char in a container and whenever a char
 * repeats, we will use its last seen index to find out what the answer was at that time.
 * Therefore, repetitions = count[last_index[i]];
 * Time : O(n), space : O(n) 
 */ 
class Solution{
public:
    int countSub(string s)
    {
        vector<int> last(256, -1); // store last seen index. Initially all are -1.
        int n = s.length();
        int dp[n + 1] = {0}; // to store computed results.
        dp[0] = 1;
        for(int i = 1; i <= n; ++i)
        {
            dp[i] = 2 * dp[i - 1];
            if(last[s[i - 1]] != -1)
                dp[i] = dp[i] - dp[last[s[i - 1]]]; // subtract the repeting subsequences.
            last[i - 1] = (i - 1);
        }
        return dp[n];
    }
};
/* Now, we can also do it without the dp array. We can store the count in the "last" vector itself so that we can directly 
 * substract it as shown below: Time : O(n), space : O(1)
 * vector<int> last(256, 0);
 * int count = 1;
 * for(int i = 1; i < s.length(); ++i){
    int prev = count;
    count = 2*count - last[s[i - 1]];
    last[s[i - 1]] = prev; // store the count when this char was encountered(count before using this char)
}
return count;
