// https://leetcode.com/problems/4sum/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4)return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++){
            if(i > 0 && nums[i] == nums[i-1])continue;
            //nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target will cause overflow
            if(nums[i] + nums[i+1] > target - nums[i+2] - nums[i+3] )break;
            if(nums[i] + nums[n-3] < target - nums[n-2] - nums[n-1]) continue;
            for(int j = i+1; j < n-2; j++){
                if(j > i+1 && nums[j] == nums[j-1])continue;
                if(nums[i] + nums[j] > target - nums[j+1] - nums[j+2])break;
                if(nums[i] + nums[j] < target - nums[n-2] - nums[n-1]) continue;
                int left = j+1;
                int right = n-1;
                while(left < right){
                    int newTarget = target-(nums[i] + nums[j]);
                    if(nums[left] + nums[right] == newTarget){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[++left]);
                        while(left < right && nums[right] == nums[--right]);
                    }
                    else if(nums[left] + nums[right] < newTarget){
                        while(left < right && nums[left] == nums[++left]);
                    }else{
                        while(left < right && nums[right] == nums[--right]);
                    }
                }
            }   
        }
        return ans;
    }
};