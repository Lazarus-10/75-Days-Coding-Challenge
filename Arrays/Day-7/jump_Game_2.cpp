// https://leetcode.com/problems/jump-game-ii/submissions/
#include <bits/stdc++.h>
using namespace std;

class Solution {
// private:
//     int dfs(vector<int> &nums, int i, vector<int> &dp){
//         if(i >= nums.size()-1)return 0;
//         if(dp[i] != -1)return dp[i];
//         int ans = 1e5;
//         for(int j=0; j<nums[i]; j++){
//             ans = min(ans, 1+dfs(nums, i+j+1, dp));
//         }
//         return dp[i] = ans;
//     }
// public:
//     int jump(vector<int>& nums) {
//         vector<int> dp(nums.size(), -1);
//         return dfs(nums, 0, dp);
//     }
    
public:
    // T.C - O(N^2)
    
    // int jump(vector<int> &nums){
    //     int pos = nums.size()-1;
    //     int ans = 0;
    //     while(pos
    //         int i = 0;
    //         while(i < pos && i + nums[i] < pos){
    //             i++;
    //         }
    //         pos = i;
    //         ans++;
    //     }
    //     return ans;
    // }
    
    // T.C : O(N)
    int jump(vector<int> &nums){
        if(nums.size() < 2)return 0;
        int maxReachable = 0, lastJumpedPos = 0, jump = 0;
        int i=0;
        while(lastJumpedPos < nums.size()-1){
            maxReachable = max(maxReachable, i + nums[i]);
            if(i == lastJumpedPos){
                jump++;
                lastJumpedPos = maxReachable;
            }
            i++;
        }
        return jump;
    }
};