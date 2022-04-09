// https://leetcode.com/problems/jump-game/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // int n = nums.size();
        // if(n <= 1)return true;
        // int maxReachable = 0, lastJumpedPos = 0;
        // int i=0;
        // while(lastJumpedPos < n-1){
        //     if(i > maxReachable)return false;
        //     maxReachable = max(maxReachable, i + nums[i]);
        //     if(i == lastJumpedPos){
        //         lastJumpedPos = maxReachable;
        //     }
        //     i++; 
        // }
        // return true;
        
        
//         int maxIndx = 0, n = nums.size();
//         for(int i = 0; i<n && maxIndx < n-1; i++){
//             if(i > maxIndx)return false;
//             maxIndx = max(maxIndx, i + nums[i]);
//         }
//         return true;
        
        
        
        int n = nums.size();
        int steps = nums[0];
        for(int i=1; i<n; i++){
            steps--;
            if(steps < 0)return false;
            if(steps < nums[i])
                steps = nums[i];
        }
        return true;
    }
};