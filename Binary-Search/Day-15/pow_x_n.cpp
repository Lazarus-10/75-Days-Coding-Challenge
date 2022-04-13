// https://leetcode.com/problems/powx-n/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    double helper(double x, int n){
        if(n == 0)return 1;
        double num = helper(x, n/2);
        num = num*num;
        if(n&1){
            num = x*num;
        }
        return num;
    }
public:
    double myPow(double x, int n) {
        double ans = helper(x, n);
        return n < 0 ? 1/ans : ans;
    }
    
};