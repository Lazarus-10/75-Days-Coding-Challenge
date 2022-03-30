// https://leetcode.com/problems/pascals-triangle/submissions/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // if(numRows == 1)return {{1}};
        // else if(numRows == 2)return {{1}, {1,1}};
        // vector<vector<int> > ans{{1}, {1,1}};
        // for(int i=3; i<=numRows; i++){
        //     vector<int> toPush;
        //     toPush.push_back(1);
        //     for(int j=0; j<ans[i-2].size()-1; j++){
        //         toPush.push_back(ans[i-2][j] + ans[i-2][j+1]);
        //     }
        //     toPush.push_back(1);
        //     ans.push_back(toPush);
        // }
        // return ans;
        
        vector<vector<int>> ans(numRows);
        for(int i=0; i<numRows; i++){
            ans[i].resize(i+1);
            ans[i][0] = ans[i][i] = 1;
            for(int j=1; j<i; j++){
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }
};