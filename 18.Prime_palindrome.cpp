/* Prime Palindrome -- Good question, the observation is also very nice.
 * Find the smallest prime palindrome greater than or equal to N.
 * Question Link: https://leetcode.com/problems/prime-palindrome/
 
 * Observation: Either the answer will be of odd length or even length. Lets see the palindromes of even length, 11, 1111, 1001,
 * 111111, 100001 etc. All these numbers are multiple of 11. In general, any even length palindrome "abcddcba" can be written
 * as (a*10000001*10^0 + b*100001*10^1 + c*1001*10^2 + d*11*10^3). Now, out of all the even length palindromes,only 11 is prime
 * Also, 2, 3, 5, 7 are their own solutions. So for 8 <= N <= 11, the answer is 11. For other numbers we will just find the odd
 * palindromes and check if that is prime or not.
*/

class Solution{
public:
    int primePalindrome(int N)
    {
        if(8 <= N && 11 >= N) return 11;

        for(int i = 1; i < 100000; ++i) // the bound "100000" is taken bcoz the question description mentions that answer lies
        {                               // below 2*10^8

            string p = to_string(i), q(p.rbegin(), p.rend()); // q is the reverse of string p
            int num = stoi(p + q.substr(1)); // since the length is odd, 0th char of q and last char of p will be common. So we                                              // skip the 0th char of q and take substring from 1st char.
            if(num >= N && isPrime(num)) return num;
        }
    }

    bool isPrime(int num)
    {
        if(num < 2 || num % 2 == 0) return num == 2;

        for(int i = 3; i*i <= num; ++i)
        {
            if(num % i == 0) return false;
        }

        return true;
    }
};
