// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=1, n = nums.size();
        while(j < n && nums[j] == nums[i]){
            j++;
        }
        while(j < n){
            while(j < n-1 && nums[j] == nums[j+1]){
                j++;
            }
            swap(nums[++i], nums[j++]);
        }
        return i+1;
      
        // Another Approach
        // int count = 0; 
        // for(int i=1; i<n; i++){
        //     if(nums[i] == nums[i-1])count++;
        //     else nums[i-count] = nums[i];
        // }
        // return n - count;
    }
};