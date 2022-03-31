// https://leetcode.com/problems/game-of-life/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<int> newState(m*n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int currState = board[i][j];
                int deadNbr = 0, liveNbr = 0;
                if(i-1 >= 0 && j-1 >= 0){
                    board[i-1][j-1] == 1 ? liveNbr++ : deadNbr++;
                }
                if(i+1 < m && j+1 < n){
                    board[i+1][j+1] == 1 ? liveNbr++ : deadNbr++;
                }
                if(i-1 >= 0 && j+1 < n){
                    board[i-1][j+1] == 1 ? liveNbr++ : deadNbr++;
                }
                if(i+1 < m && j-1 >= 0){
                    board[i+1][j-1] == 1 ? liveNbr++ : deadNbr++;
                }
                if(i-1 >= 0 ){
                    board[i-1][j] == 1 ? liveNbr++ : deadNbr++;
                }
                if(j-1 >= 0 ){
                    board[i][j-1] == 1 ? liveNbr++ : deadNbr++;
                }
                if(i+1 < m){
                    board[i+1][j] == 1 ? liveNbr++ : deadNbr++;
                }
                if(j+1 < n ){
                    board[i][j+1] == 1 ? liveNbr++ : deadNbr++;
                }
                    
                if(currState == 1){
                    if(liveNbr < 2 || liveNbr > 3){
                        newState[i*n + j] = 0;
                    }else{
                        newState[i*n + j] = 1;
                    }
                }else{
                    if(liveNbr == 3){
                        newState[i*n + j] = 1;
                    }else{
                        newState[i*n + j] = 0;
                    }
                }
            }
        }
        for(int i=0, k=0; i<m; i++){
            for(int j=0; j<n; j++){
                board[i][j] = newState[k++];
            }
        }
    }
};