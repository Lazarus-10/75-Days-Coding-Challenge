// https://leetcode.com/problems/first-missing-positive/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // unordered_set<int> st;
        // for(int x:nums){
        //     st.insert(x);
        // }
        // for(int i=1; ;i++){
        //     if(st.find(i) == st.end())
        //         return i;
        // }
        // return -1;
        
        // we are putting the element at its correct position(eg, 1 at index 0, 2 at indx 1)
        // The answer is always going to be in the range [1, n+1]
        
        // int n = nums.size();
        // for(int i = 0; i<n; i++){
        //     while(nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]){
        //         swap(nums[i], nums[nums[i] - 1]);
        //     }
        // }
        // for(int i=0; i<n; i++){
        //     if(nums[i] != i+1)return i+1;
        // }
        // return n+1;
        
        //instead of swapping, we can just mark its correct position with negative sign
        int n = nums.size();
        for (int i = 0; i < n; i++) 
            if (nums[i] <= 0) nums[i] = n + 1;
        
        for (int i = 0; i < n; i++) 
            if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] *= -1;
        
        for (int i = 0; i < n; i++) 
            if (nums[i] > 0) return i + 1;
        
        return n + 1;
    }
    
};