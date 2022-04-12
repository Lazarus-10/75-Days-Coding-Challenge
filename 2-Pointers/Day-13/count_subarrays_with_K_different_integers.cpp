// https://leetcode.com/problems/subarrays-with-k-different-integers/
// https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/235235/C%2B%2BJava-with-picture-prefixed-sliding-window
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
        // count subarrays with atmost k unique integers
        int subarraysWithAtMostKDistinct(vector<int>& nums, int k){
            unordered_map<int, int> mp;
            int start = 0, diff = 0;
            int ans = 0;
            for(int end = 0; end < nums.size(); end++){
                if(mp[nums[end]]++ == 0)diff++;
                while(diff > k){
                    if(--mp[nums[start++]] == 0)diff--;
                }
                ans += end - start + 1;
            }
            return ans;
        }
public:
    // int subarraysWithKDistinct(vector<int>& nums, int k) {
    //     unordered_map<int, int> mp;
    //     int start = 0, prefix = 0, ans = 0;
    //     int diff = 0; // different elements in the current window
    //     for(int end = 0; end < nums.size(); end++){
    //         if(mp[nums[end]]++ == 0)diff++;
    //         // as previously it must have been k, so we will move the start pointer by 1
    //         // why diff-- without checking if mp[start] might be greater than 1???
    //         // because if it was greater than 1, so in the previous iteration it must have been decreased to 1 due to while loop
    //         if(diff > k){
    //             prefix = 0;
    //             diff--;
    //             --mp[nums[start++]];
    //         }
    //         while(mp[nums[start]] > 1){
    //             ++prefix;
    //             --mp[nums[start++]];
    //         }
    //         if(diff == k) ans += prefix + 1;
    //     }
    //     return ans;
    // }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Atmost(k) - Atmost(k-1) = exact(k);
        return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k-1);
    }
};      