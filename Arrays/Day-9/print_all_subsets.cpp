// https://leetcode.com/problems/subsets/submissions/
// Discussion : https://leetcode.com/problems/subsets/discuss/27278/C%2B%2B-RecursiveIterativeBit-Manipulation
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void recurse(vector<vector<int>> &ans, vector<int>& nums, vector<int>& temp, int i){
        if(i >= nums.size()){
            ans.push_back(temp);
            return;
        }
        recurse(ans, nums, temp, i+1);
        temp.push_back(nums[i]);
        recurse(ans, nums, temp, i+1);
        temp.pop_back();
    }
public:
    // Recursive
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     vector<int> temp;
    //     recurse(ans, nums, temp, 0);
    //     return ans;
    // }

    // Iterative
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        for(int x : nums){
            for(int i=0, n = ans.size(); i<n; i++){
                ans.push_back(ans[i]);
                ans.back().push_back(x);
            }
        }
        return ans;
    }
    
};