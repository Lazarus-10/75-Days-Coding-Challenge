// https://leetcode.com/problems/peak-index-in-a-mountain-array/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0, end = arr.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid] < arr[mid+1]){
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return start;
        
        // int start = 1, end = arr.size()-2;
        // while(start <= end){
        //     int mid = start + (end-start)/2;
        //     if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
        //         return mid;
        //     }else if(arr[mid] < arr[mid+1]){
        //         start = mid+1;
        //     }else{
        //         end = mid-1;
        //     }
        // }
        // return -1;
        
        
        // int left = 0;
        // while (arr[left] < arr[left+1]) left++;
        // return left;
        
    }
};