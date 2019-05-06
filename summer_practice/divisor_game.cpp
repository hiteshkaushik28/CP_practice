/*
    Question : https://leetcode.com/problems/divisor-game/
    Such a great question
    First thing : Both players will play optimally
    Optimal Strategy : 
    case 1 : when N is even
    a) Alice will choose 1 and make result odd (even - 1 = odd)
    b) Bob now can only choose an odd number as odd number only have odd divisors. Also bob make the result even (odd - odd = even)
    c) Again the situation is same as a) part. Eventually Alice will give N = 1 to Bob and he will not be able to proceed.
    Hence, Alice wins.

    case 2 : when N is odd
    a) Alice chooses an odd divisor (he is constrained) and make result as even.
    b) Now Bob can use the same strategy as in case 1 and will eventually give N = 1 to Alice.
    Hence, Alice looses.

    The above solution is a mathematical approach.
    Lets see the DP approach : 
    base case :
    N = 0 or 1 --> False

    for each n = 2, 3, 4, ....., N
    go till n - 1 and check if a divisor exists
    if yes, then check if n - divisor is false, if yes then it means current player will win for given n.So set dp[n] = true
    return dp[N] at last.
*/

class Solution
{
    public:
        // mathematical version
        bool divisorGame(int N)
        {
            return (N % 2 == 0);
        }

        //DP version
        bool divisorGame(int N)
        {
            bool dp[N+1] = {0};
            for(int i = 2; i <= N; ++i)
            {
                for(int j = 1; j < i; ++j)
                {
                    if(i % j == 0 && dp[i - j] == false)
                        dp[i] = true;
                }
            }

            return dp[N];
        }
};