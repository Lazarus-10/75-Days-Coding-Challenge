// 
#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14436/Revised-Binary-Search/191339
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int start = 0, end = arr.size()-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(arr[mid] == target)return mid;
            
            if(arr[mid] >= arr[start]){
                if(target >= arr[start] && target < arr[mid]){
                    end = mid -1;
                }else{
                    start = mid + 1;
                }
            }else{
                if(target > arr[mid] && target <= arr[end]){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

// https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/154836/The-INF-and-INF-method-but-with-a-better-explanation-for-dummies-like-me
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int start = 0, end = arr.size()-1;
        int comparator;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(((target < arr[0])&&(arr[mid] < arr[0])) || ((target >= arr[0]) && arr[mid] >= arr[0])){
                comparator = arr[mid];
            }else{
                if(target < arr[0]){
                    comparator = -1e5;
                }else{
                    comparator = 1e5;
                }
            }
            if(target == comparator){
                return mid;
            }else if(target < comparator){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return -1;
    }
};