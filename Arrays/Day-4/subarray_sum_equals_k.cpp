// https://leetcode.com/problems/subarray-sum-equals-k/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        int sum = 0;
        mp[sum] = 1;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int remaining = sum - k;
            if(mp.find(remaining) != mp.end()){
                count += mp[remaining];
            }
            mp[sum]++;
        }
        return count;
    }
};