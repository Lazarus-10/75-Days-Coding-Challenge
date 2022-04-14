// https://leetcode.com/problems/search-a-2d-matrix/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0, end = row*col - 1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(matrix[mid/col][mid%col] == target)return true;
            else if(matrix[mid/col][mid%col] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return false;
    }
};