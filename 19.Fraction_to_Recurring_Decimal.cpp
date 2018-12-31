/* Fraction To Recurring Decimal

 * Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
 * If the fractional part is repeating, enclose the repeating part in parentheses.

 * Question Link: https://leetcode.com/problems/fraction-to-recurring-decimal/

 * IDEA : Quotient starts repeating only when remainder starts repeating. So using this observation, we can store remainders
 * and check for their existence and accordingly place the parenthesis.
*/
class Solution{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if(!numerator) return "0";

        string ans = "";
        long n = labs(numerator);
        long d = labs(denominator);
        long quotient = n / d;
        long rem = n % d;

        ans += to_string(quotient);
        if(!rem) return ans;
        ans += ".";
        rem *= 10;
        
        unordered_map<long, long> mymap; // stores the position of remainder 
        while(rem)
        {
            if(mymap.find(rem) != mymap.end()) // check if this remainder is seen before
            {
                ans.insert(mymap[rem], 1, "("); // if seen, the
                ans += ")"; // close the braces
                return ans;
            }
            
            mymap[rem] = ans.size(); // if not, then store the location of this remainder using the corresponding quotient.
            quotient = rem / d;
            ans += to_string(quotient);
            rem = (rem % d) * 10;
        }

        return ans;
    }
};
