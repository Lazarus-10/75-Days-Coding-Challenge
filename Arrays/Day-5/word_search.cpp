// https://leetcode.com/problems/word-search/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool helper(vector<vector<char>>& board, string& word, int i, int j, int indx){
        if(indx == word.size())return true;
        if(i<0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[indx])
            return false;
        char c = board[i][j];
        board[i][j] = '#';
        bool ret = helper(board, word, i, j+1, indx+1) 
                || helper(board, word, i+1, j, indx+1) 
                || helper(board, word, i, j-1, indx+1) 
                || helper(board, word, i-1, j, indx+1);
        board[i][j] = c;
        return ret;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int indx = 0;
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(helper(board, word, i, j, indx))return true;
            }
        }
        return false;
    }
};