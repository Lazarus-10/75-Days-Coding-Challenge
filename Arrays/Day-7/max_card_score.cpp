// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Discussion: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/597825/Simple-Clean-Intuitive-Explanation-with-Visualization
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0;
        for(int i=0; i<k; i++){
            lsum += cardPoints[i];
        }
        int ans = lsum;
        for(int i=0, rsum = 0; i<k; i++){
            lsum -= cardPoints[k-1-i];
            rsum += cardPoints[cardPoints.size()-1-i];
            ans = max(ans, lsum + rsum);
        }
        return ans;
    }
};