// https://leetcode.com/problems/squares-of-a-sorted-array/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int k = n-1;
        int start = 0, end = n - 1;
        while(start <= end){
            if(abs(nums[start]) > nums[end]){
                ans[k--] = nums[start]*nums[start++];
            }else{
                ans[k--] = nums[end]*nums[end--];
            }
        }
        return ans;
        
        // vector<int> ans;
        // int n = nums.size();
        // int i=0;
        // while(i < n && nums[i] < 0)i++;
        // int j = i-1;
        // while(j >= 0 && i < n){
        //     if(abs(nums[j]) < nums[i])ans.push_back(nums[j]*nums[j--]);
        //     else ans.push_back(nums[i]*nums[i++]);
        // }
        // while(i < n){
        //     ans.push_back(nums[i]*nums[i++]);
        // }while(j >=0){
        //     ans.push_back(nums[j]*nums[j--]);
        // }
        // return ans;
    }
};