// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/discuss/769698/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(vector<int>& weights, int capacity, int days){
        int day = 1;
        int currLoad = 0;
        for(int weight : weights){
            currLoad += weight;
            if(currLoad > capacity){
                day++;
                currLoad = weight;
            }
            if(day > days)return false;
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        int maxWeight = 0;
        for(int x : weights){
            maxWeight = max(maxWeight, x);
            sum += x;
        }
        // The minimum possible capacity should be greater than maximum weight
        // and macx possible is sum of all weights
        int start = maxWeight, end = sum;
        while(start < end){
            int mid = start + (end-start)/2;
            // cout << "for mid = " << mid; 
            if(isPossible(weights, mid, days)){
                // cout << " -> possible";
                end = mid;
                // cout << "(" << start << ", " << end << ")" << endl;
            }else{
                // cout << " -> NOT possible";
                start = mid + 1;
                // cout << "(" << start << ", " << end << ")" << endl;
            }
        }
        return end;
    }
};