// https://leetcode.com/problems/max-value-of-equation/
// https://leetcode.com/problems/max-value-of-equation/discuss/1472281/The-math-behind-it-and-how-to-reason-the-solution
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // int n = points.size();
        // int ans = INT_MIN;
        // for(int i=0; i<n; i++){
        //     for(int j = i+1; j<n; j++){
        //         if(abs(points[i][0] - points[j][0]) <= k){
        //             ans = max(ans, abs(points[i][0]-points[j][0]) + points[i][1] + points[j][1]);
        //         }else break;
        //     }
        // }
        // return ans;
        
        // Intution: TO find MAX(yi + yj + |xi - xj|)
        // As we know array is sorted by x-values
        // so for j > i, |xi - xj| = xj - xi
        // hence we have to find MAX(yi + yj + xj - xi);
        // or MAX((yj + xj ) + (yi - xi))
        // for a fixed point (xj, yj): (xi + yj) will be fixed and we just have to find MAX(yi-xi)
        // so we can maintain a max heap which will maintain (yi-xi)
        
        // priority_queue<pair<int, int>> pq; // max-heap
        // pq.push({points[0][1] - points[0][0], points[0][0]});
        // int ans = INT_MIN;
        // for(int j=1; j<points.size(); j++){
        //     int sum = points[j][0] + points[j][1];
        //     while(!pq.empty() && points[j][0] - pq.top().second > k){
        //         pq.pop();
        //     }
        //     if(!pq.empty()){
        //         ans = max(ans, sum + pq.top().first);
        //     }
        //     pq.push({points[j][1] - points[j][0], points[j][0]});
        // }
        // return ans;
        
        deque<int> dq;
        int ans = INT_MIN;
        for(int i=0; i<points.size(); i++){
            // remove all the front elements whose difference is greater than k
            while(dq.size() && points[i][0]-points[dq.front()][0] > k) dq.pop_front();
            if(dq.size()){
                ans = max(ans, points[i][0] + points[i][1] + points[dq.front()][1] - points[dq.front()][0]);
            }
            // remove all the back elements whose difference is smaller than (yi-xi)
            int currDiff = points[i][1] - points[i][0];
            while(dq.size() and points[dq.back()][1] - points[dq.back()][0] < currDiff)
                dq.pop_back();
            dq.push_back(i);
        }
        return ans;
        
        
    }
};