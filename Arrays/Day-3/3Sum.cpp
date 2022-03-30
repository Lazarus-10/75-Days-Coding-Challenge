// https://leetcode.com/problems/3sum/
// Best Explanation: https://leetcode.com/problems/3sum/discuss/1462423/C%2B%2B-or-Both-Two-Pointers-and-HashMap-Approach-Explained

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)return {};
        sort(nums.begin(), nums.end());
        if(nums[0] > 0)return {}; // if the first number is positive, then all others will also will be positive
        
        vector<vector<int> > ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0)break; //because all cases will be covered in negative numbers
            if(i > 0 && nums[i] == nums[i-1])continue; // move till the last occurence of duplicate number
            int low = i+1, high = n-1;
            int sum = 0;
            while(low < high){
                sum = nums[i] + nums[low] + nums[high];
                if(sum > 0)high--;
                else if(sum < 0)low++;
                else{
                    ans.push_back({nums[i], nums[low], nums[high]});
                    while(low < high && nums[low] == nums[++low]); // avoiding duplicates again
                    while(low < high && nums[high] == nums[--high]);
                }
            }
        }
        return ans;

        //Hash-Map approach
        // int n = nums.size();
        // if(n < 3)return {};
        // sort(nums.begin(), nums.end());
        // if(nums[0] > 0)return {};
        // unordered_map<int, int> mp;
        // for(int i=0; i<n; i++){
        //     mp[nums[i]] = i;
        // }
        // vector<vector<int>> ans;
        // for(int i=0; i<n-2; i++){
        //     if(nums[i] > 0)break;
        //     for(int j=i+1; j<n-1; j++){
        //         int requiredSum = -1*(nums[i] + nums[j]);
        //         if(mp.count(requiredSum) && mp.find(requiredSum)->second > j){
        //             ans.push_back({nums[i], nums[j], requiredSum});
        //         }
        //         j = mp.find(nums[j])->second; //move j to the index of last occurence of current element and then j++ will get executed due to for loop
        //     }
        //     i = mp.find(nums[i])->second;
        // }
        // return ans;
    }
};