/* Best Time to Buy and Sell Stock with Cooldown
 * A good question involving DP 
 * Question Link: //leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown 

 ****** QUESTION ******
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one 
   share of the stock multiple times) with the following restrictions:

 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
*/


/*******************  IDEA *****************/
/*
 * The solution involves DP.
 * On a given day, we can BUY, SELL, or COOLDOWN.
 * The conditions:
 * a) COOLDOWN: There are no conditions for doing cooldown on a day.
 * b) BUY:      To buy or "own" a stock on "i"th day, we must not "own" any stock by the end of day "i - 2". This is because,
                if we want to buy on ith day, then "i - 1"th day must be a cooldown and before that we must not own any stock.
 * c) SELL:     To sell or "not_own" a stock on "i"th day, we must "own" a stock by the end of "i - 1"th day.

 * Let own[i] represent the profit by owning a stock by the end of day "i".
 * Let not_own[i] represent the profit by not owning any stock by the end of day "i".

 * own[i] = max(own[i - 1], not_own[i - 2] - price[i]); // either don't buy or buy it today
 * not_own[i] = max(not_own[i - 1], own[i - 1] + price[i]); // either don't sell or sell it today 
 * IT IS CLEARY VISIBLE THAT OPERATION ON DAY "i" DEPENDS ONLY ON DAY "i - 1" AND "i - 2". SO IT CAN BE DONE IS O(1) SPACE.
*/

Class Solution{
public:
    int maxProfit(vector<int> &prices){
    int n = prices.length();
    if(n < 1)
        return 0;
    int own_last = -prices[0];
    int own_last_prev = 0;
    int not_own_last = 0;
    not_own_last_prev = 0;
    int profit = 0;
    for(int i = 1; i < n; ++i)
    {
        int own = max(own_last, not_own_last_prev - prices[i]);
        int not_own = max(not_own_last, own_last + prices[i]);

        own_last_prev = own_last;
        own_last = own;
        not_own_last_prev = not_own_last;
        not_own_last = not_own;
        profit = max(profit, max(own, not_own));
    }

    return profit;
    }
}       
