// https://leetcode.com/problems/two-sum/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int secondNumber = target - nums[i];
            if(mp.find(secondNumber) != mp.end()){
                return {i, mp[secondNumber]};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};