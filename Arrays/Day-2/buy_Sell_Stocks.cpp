//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // prices.push_back(0);
        // int start = prices[0];
        // int profit = 0;
        // for(int i=1; i<prices.size(); i++){
        //     if(prices[i] < prices[i-1]){
        //         profit += prices[i-1] - start;
        //         start = prices[i];
        //     }
        // }
        // return profit;
        
        //valley-peak Approach
        // int i=0, buy, sell, profit = 0;
        // int n = prices.size();
        // while(i < n-1){
        //     while(i < n-1 && prices[i+1] <= prices[i]){
        //         i++;
        //     }
        //     buy = prices[i];
        //     while(i < n-1 && prices[i+1] > prices[i]){
        //         i++;
        //     }
        //     sell = prices[i];
        //     profit += sell - buy;
        // }
        // return profit;
        
        //Faster Approach
        int profit = 0;
        for(int i=1; i<prices.size(); i++){
            profit += max(prices[i]-prices[i-1], 0);
        }
        return profit;
    }
};