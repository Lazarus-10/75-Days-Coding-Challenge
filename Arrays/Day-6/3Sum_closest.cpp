// https://leetcode.com/problems/3sum-closest/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        for(int i=0; i<n-2; i++){
            if(i > 0 && nums[i] == nums[i-1])continue;  
            int low = i+1, high = n-1;
            while(low < high){
                int currSum = nums[i] + nums[low] + nums[high];
                if(currSum == target)return currSum;
                if(abs(currSum - target) < abs(closestSum - target)){
                    closestSum = currSum;
                }
                if(currSum > target){
                    high--;
                }else low++;
            }
        }
        return closestSum;
    }
};