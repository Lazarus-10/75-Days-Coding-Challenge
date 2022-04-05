// https://leetcode.com/problems/combination-sum/
// Discussion: https://leetcode.com/problems/combination-sum/discuss/16496/Accepted-16ms-c%2B%2B-solution-use-backtracking-easy-understand.
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &temp, int i){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        while(i < candidates.size() && candidates[i] <= target){
            temp.push_back(candidates[i]);
            dfs(candidates,target - candidates[i], ans, temp, i);
            temp.pop_back();
            i++;
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        vector<vector<int>> ans;
        dfs(candidates, target, ans, combination, 0);
        return ans;
    }
};