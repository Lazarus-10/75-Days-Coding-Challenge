// https://leetcode.com/problems/sort-colors/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0, mid=0, end = nums.size()-1;
        // 0 to start is 0, start to mid is 1's and mid to end is 2's
        while(mid <= end){
            // as we know 0 to mid is 0 and 1's so increment both
            if(nums[mid] == 0){
                swap(nums[start++], nums[mid++]);
            }else if(nums[mid] == 2){ 
                // after swapping we might get 0 at mid, so don't increment mid
                swap(nums[end--], nums[mid]);
            }else mid++;
        }
    }
};