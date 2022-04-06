// https://leetcode.com/problems/max-area-of-island/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& grid, int &curr_Max, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || !grid[i][j])return;
        curr_Max++;
        grid[i][j] = 0; // we can also use visited array to avoid modifying grid
        // just write if(vis[i][j])return
        // vis[i][j] = 1;
        dfs(grid, curr_Max, i, j-1);
        dfs(grid, curr_Max, i, j+1);
        dfs(grid, curr_Max, i-1, j);
        dfs(grid, curr_Max, i+1, j);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]){
                    int curr_Max = 0;
                    dfs(grid, curr_Max, i, j);
                    ans = max(ans, curr_Max);
                }
            }
        }
        return ans;
    }
};