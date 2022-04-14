// https://leetcode.com/problems/divide-two-integers/discuss/1516367/Complete-Thinking-Process-or-Intuitive-Explanation-or-All-rules-followed-or-C%2B%2B-code
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)return 1;
        if(dividend == INT_MIN && divisor == -1)return INT_MAX;
        bool isPositive = dividend > 0 ^ divisor > 0 ? 0 : 1;
        unsigned int dvnd = abs(dividend);
        unsigned int dvsr = abs(divisor);
        unsigned int ans = 0;
        while(dvnd >= dvsr){
            short q = 0;
            while((dvsr << (q+1)) < dvnd){
                q++;
            }
            ans += (1 << q);
            dvnd -= (dvsr << q);
        }
        
        return isPositive ? ans  : -ans;
    }
};