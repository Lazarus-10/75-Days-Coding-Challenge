// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findLeftIndex(vector<int>& nums, int target){
        int start = 0, end = nums.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] < target)start = mid + 1;
            else end = mid - 1;
        }
        return start < nums.size() && nums[start] == target ? start : -1;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!nums.size())return {-1, -1};
        int leftIndex = findLeftIndex(nums, target);
        if(leftIndex == -1)return {-1, -1};
        //Searching for the rightIndex
        int start = leftIndex, end = nums.size()-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] <= target)start = mid + 1;
            else end = mid -1;
        }
        int rightIndex =  end;
        return {leftIndex, rightIndex};
    }
};

// class Solution {
// public:
    
//     int getFirst(vector<int> &nums,int target){
//                 int s =0;
//                 int e = nums.size()-1;
//                 int ans =-1;
//                 while(s<=e){
//                     int mid = s+(e-s)/2;
//                     if(nums[mid] == target){
//                         ans = mid;
//                         e = mid-1;
//                     }
//                     else if(nums[mid]>target){
//                         e = mid-1;
//                     }
//                     else{
//                         s = mid+1;
//                     }

//                 }
//             return ans;
//          }

//          int getLast(vector<int> &nums,int target, int s){
//                 int e = nums.size()-1;
//                 int ans =-1;
//                 while(s<=e){
//                     int mid = s+(e-s)/2;
//                     if(nums[mid] == target){
//                         ans = mid;
//                         s = mid+1;
//                     }
//                     else if(nums[mid]>target){
//                         e = mid-1;
//                     }
//                     else{
//                         s = mid+1;
//                     }

//                 }
//             return ans;


//         }
    
//     vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int> v(2,-1);
//             int first = getFirst(nums,target);
//             if(first == -1)
//                 return v;
//             int last = getLast(nums,target, first);
//             v[0] = first;
//             v[1] = last;
//             return v;
//     }
// };