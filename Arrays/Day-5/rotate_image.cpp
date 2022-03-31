// https://leetcode.com/problems/rotate-image/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //Transpose
        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // mirror
        int i = 0, j = n-1;
        while(i < j){
            for(int k=0; k<n; k++){
                swap(matrix[k][i], matrix[k][j]);
            }
            i++, j--;
        }
    }
};