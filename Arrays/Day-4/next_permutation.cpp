// https://leetcode.com/problems/next-permutation/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)return;
        if(nums[n-1] > nums[n-2]){
            swap(nums[n-1], nums[n-2]);
            return;
        }
        int i = n-2;
        while(i >= 1 && (nums[i] <= nums[i-1])){
            i--;
        }
        reverse(nums.begin()+i, nums.end());
        if(i > 0){
            auto it = upper_bound(nums.begin()+i, nums.end(), nums[i-1]);
            swap(nums[i-1], nums[it - nums.begin()]);
        }
    }
};