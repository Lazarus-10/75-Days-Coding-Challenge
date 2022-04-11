// https://leetcode.com/problems/partition-labels/
// https://leetcode.com/problems/partition-labels/discuss/1868842/JavaC%2B%2B-VISUALLY-EXPLAINEDDDDD!!
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        // unordered_map<char, pair<int,int>> mp;
        // for(int i=0; i<s.length(); i++){
        //     if(mp.find(s[i]) != mp.end()){
        //         mp[s[i]].second = i;
        //     }else{
        //         mp[s[i]] = {i, i};
        //     }
        // }
        // vector<pair<int, int> > v;
        // for(auto x : mp){
        //     v.push_back(x.second);
        // }
        // sort(v.begin(), v.end());
        // vector<int> ans;
        // int start = v[0].first;
        // int end = v[0].second;
        // for(int i=1; i<v.size(); i++){
        //     if(v[i].first <= end){
        //         end = max(end, v[i].second);
        //     }else{
        //         ans.push_back(end-start+1);
        //         start = v[i].first;
        //         end = v[i].second;
        //     }
        // }
        // ans.push_back(end-start+1);
        // return ans;
        
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]] = i;
        }
        vector<int> ans;
        int prev = -1;
        int maxi = 0;
        for(int i=0; i<s.size(); i++){
            maxi = max(maxi, mp[s[i]]);
            if(i == maxi){
                ans.push_back(maxi - prev);
                prev = maxi;
            }
        }
        return ans;
    }
};