// https://leetcode.com/problems/k-diff-pairs-in-an-array/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int &x : nums)   {
            mp[x]++;
        }
        int ans = 0;
        if(k == 0){
            for(auto x : mp){
                if(x.second > 1){
                    ans++;
                }
            }
            return ans;
        }
        
        for(auto p : mp){
            if(mp.find(p.first + k) != mp.end())ans++;
        }
        // for(int i=0; i<nums.size(); i++){
        //     if(mp.find(nums[i]) != mp.end()){
        //         if(mp.find(nums[i] - k) != mp.end())ans++;
        //         if(mp.find(nums[i] + k) != mp.end())ans++;
        //         mp.erase(nums[i]);
        //     }
        // }
        return ans;
    }
    
    // T.C: O(NLogN), but useful(O(N)) if the array given is sorted
    
    // int findPairs(vector<int>& nums, int k) {
    //     sort(nums.begin(), nums.end());
    //     int ans = 0, i = 0, j = 1;
    //     for(i, j; i<nums.size() && j<nums.size(); ) {
    //         if(i==j || nums[j]-nums[i]<k) j++;
    //         else {
    //             if(nums[j]-nums[i]==k) {
    //                 ans++;
    //                 j++;
    //                 while(j<nums.size() && nums[j]==nums[j-1]) j++; // remove redundant
    //             }
    //             i++;
    //             while(i<j && nums[i]==nums[i-1]) i++; // remove redundant
    //         }
    //     }
    //     return ans;
    // }
};