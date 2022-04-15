// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/discuss/1064548/JavaC%2B%2BPython-Binary-Search
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(vector<int>& nums,int &penalty, int &maxOperations){
        int count = 0;
        for(int n : nums){
            // number of operations required to split this bag with maximum value mid
            count += (n-1)/penalty; 
            if(count > maxOperations)return false;
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
       int start = 1, end = *max_element(nums.begin(), nums.end());
        while(start < end){
            // current penalty
            int mid = (start + end) >> 1;
            if(isPossible(nums, mid, maxOperations)){
                end = mid;
            }else{
                start = mid + 1;
            }
        }
        return end;
    }
};