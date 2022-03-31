// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
//         unordered_map<int, int> mp;
//         for(auto x : time){
//             mp[x%60]++;
//         }
//         int ans = 0;
//         for(auto x : mp){
//             int n = x.second;
//             if(x.first == 30 || x.first == 0){
//                 if(n&1){
//                     ans += (n-1)/2*n;
//                 }else{
//                     ans += n/2*(n-1);
//                 }
//             }else{
//                 if(mp.find(60 - x.first) != mp.end()){
//                     ans += n*(mp.find(60 - x.first)->second);
//                     mp.erase(60-x.first);
//                 }
//             }
            
//         }
//         return ans;
        
        int count = 0;
        int hash[60] = {0};
        for(int i=0; i<time.size(); i++){
            int num = time[i]%60;
            if(num == 0){
                count += hash[0];
            }else{
                count += hash[60 - num];
            }
            hash[num]++;
        }
        return count;
    }
};