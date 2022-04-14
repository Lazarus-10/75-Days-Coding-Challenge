// https://leetcode.com/problems/find-peak-element/
// https://leetcode.com/problems/find-peak-element/discuss/50232/Find-the-maximum-by-binary-search-(recursion-and-iteration)/186496
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        while(start < end){
            int mid = start + (end - start)/2;
            // mid hamesha center me aata hai ya ek pichhe, toh isliye mid+1 se check krne me 
            //aasani hogi otherwise mid-1 se check krne me boundary condition bhi daalna padega
           if(nums[mid] < nums[mid+1]){
               start = mid + 1;
           }else{
               end = mid;
           }
        }
        return start;
        
        // int n = nums.size();
        // if(n == 1)return 0;
        // if(nums[0] > nums[1])return 0;
        // if(nums[n-1] > nums[n-2])return n-1;
        // int start = 1, end = n-2;
        // while(start <= end){
        //     int mid = start + (end-start)/2;
        //     if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1])return mid;
        //     else if(nums[mid] < nums[mid-1])end = mid - 1;
        //     else if(nums[mid] < nums[mid+1])start = mid + 1;
        // }
        // return -1;
    }
};