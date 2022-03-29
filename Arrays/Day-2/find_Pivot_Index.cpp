// https://leetcode.com/problems/find-pivot-index/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int x : nums)sum += x;
        int pivot = 0;
        int leftSum = 0, rightSum = sum-nums[pivot];
        while(pivot < nums.size()){
            if(leftSum == rightSum)return pivot;
            leftSum += nums[pivot++];
            if(pivot < nums.size())rightSum -= nums[pivot];
        }
        return -1;
        
    }
};