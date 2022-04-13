// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(grid[row-1][col-1] >= 0)return 0;
        int prev = 0;
        int ans = 0;
        int i = row-1, j = 0;
        while(i >= 0 && j < col){
            if(grid[i][j] < 0){
                ans += col - j;
                i--;
            }else{
                j++;
            }
         }
        return ans;
    }
};