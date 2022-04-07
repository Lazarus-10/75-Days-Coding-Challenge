// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// Discussion: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/discuss/661995/Do-you-like-visual-explanation-You-got-it.-%3A-)-With-2-code-variations.
#include <bits/stdc++.h>
using namespace std;

class Solution {
    const long mod = 1e9 + 7;
    int helper(vector<int> cuts, int length){
        sort(cuts.begin(), cuts.end());
        int maxLength = max(cuts[0], length - cuts[cuts.size()-1]);
        for(int i=1; i<cuts.size(); i++){
            maxLength = max(maxLength, cuts[i] - cuts[i-1]);
        }
        return maxLength;
    }
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        return (helper(hCuts, h)%mod * helper(vCuts, w)%mod)%mod;
    }
    
//     int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
//         sort(hCuts.begin(), hCuts.end());
//         sort(vCuts.begin(), vCuts.end());
        
//         vector<int> heights = {hCuts[0]};
//         int hn = hCuts.size();
//         for(int i=1; i<hn; i++){
//             heights.push_back(hCuts[i] - hCuts[i-1]);
//         }
//         heights.push_back(h - hCuts[hn-1]);
        
//         vector<int> lengths = {vCuts[0]};
//         int vn = vCuts.size();
//         for(int i = 1; i < vn; i++){
//             lengths.push_back(vCuts[i]-vCuts[i-1]);
//         }
//         lengths.push_back(w - vCuts[vn - 1]);
        
//         int maxHeight = *max_element(heights.begin(), heights.end());
//         int maxLength = *max_element(lengths.begin(), lengths.end());
//         return (maxHeight%mod * maxLength%mod)%mod;
//     }
};