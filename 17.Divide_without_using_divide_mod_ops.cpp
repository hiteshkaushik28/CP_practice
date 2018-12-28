/* Divide Two Integers
 * Question Link: https://leetcode.com/problems/divide-two-integers/

 * Description: Given two integers dividend and divisor, divide two integers without using multiplication, division and mod 
 * operator.
 * Return the quotient after dividing dividend by divisor.
 * The integer division should truncate toward zero.
 * IDEA
 * we are asked to divide two integers. However, we are not allowed to use division, multiplication and mod operations. 
 * So, what else can we use? Yeah, bit manipulations.

 * Suppose we want to divide 15 by 3, so 15 is dividend and 3 is divisor. Well, division simply requires us to find how many 
 * times we can subtract the divisor from the the dividend without making the dividend negative.

 * We subtract 3 from 15 and we get 12, which is positive. Let's try to subtract more. Well, we shift 3 to the left by 1 bit 
 * and we get 6. Subtracting 6 from 15 still gives a positive result. Well, we shift again and get 12. We subtract 12 from 15 
 * and it is still positive. We shift again, obtaining 24 and we know we can at most subtract 12. Well, since 12 is obtained 
 * by shifting 3 to left twice, we know it is 4 times of 3. How do we obtain this 4? Well, we start from 1 and shift it to left
 * twice at the same time. We add 4 to an answer (initialized to be 0). In fact, the above process is like 15 = 3 * 4 + 3. 
 * We now get part of the quotient (4), with a remainder 3.

 * Then we repeat the above process again. We subtract divisor = 3 from the remaining dividend = 3 and obtain 0. We know we are
 * done. No shift happens, so we simply add 1 << 0 to the answer.
*/

Class Solution{
public:
    int divide(int numerator, int denominator)
    {
        // handling overflow; 1) divide by zero case, 2) INT_MIN / -1 = INT_MAX + 1
        if(!denominator || (numerator == INT_MIN && denominator == -1)) 
            return INT_MAX;

        int sign = ((numerator < 0 && denominator < 0) || (numerator >= 0 && denominator >= 0)) ? 1 : -1; // get sign of answer
        long long n = llabs(numerator); // llabs() = long long version of abs()
        long long d = llabs(denominator);

        int ans = 0;
        
        while(n >= d)
        {
            long long temp = d, multiple = 1;
            while(n >= (temp << 1))
            {
                temp <<= 1;
                multiple <<= 1;
            }

            n -= temp;
            ans += multiple;
        }

        return sign * ans;
    }
};
