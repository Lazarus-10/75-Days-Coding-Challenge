// https://leetcode.com/problems/subarray-sums-divisible-by-k/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // T.L.E
        
        // int count = 0;
        // for(int i=0; i<nums.size(); i++){
        //     int sum = 0;
        //     for(int j=i; j < nums.size(); j++){
        //         sum += nums[j];
        //         if(sum%k == 0)count++;
        //     }
        // }
        // return count;
        
        // if remainder of sum till jth index is x and remainder of sum till ith index is also x
        // then sum(i, j] is divisible by k(bcz sum(i, j] = sum[0, j] - sum[0,i])
        int count = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
       //  Why mp[0] = 1 ?
       // lets say we found x prefix sums whose remainder is 0
       // So we can either choose one prefix sum or two prefix sums to form a subArray
       // i.e  Total SubArray Count = (xC1) + (xC2) = (x+1C2) = choosing two prefix sums to form subArrays
       // e.g 5C2 + 5C1 = 6C2 = count of SubArrays with remainder 0
       // if we dont put mp[0] = 1, we can return count + mp[0](whose direct sum is divisible by k)
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int remainder = sum%k;
            if(remainder < 0)
                remainder += k;
            
            if(mp.find(remainder) != mp.end())
                count += mp[remainder];
            mp[remainder]++;
        }
        return count;
        // return count + mp[0];
    }
};