// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<int> day1(n, 0);
        // vector<int> day2(n, 0);
        
        // int buy = prices[0];
        // for(int i=1; i<n; i++){
        //     buy = min(buy, prices[i]);
        //     day1[i] = max(day1[i-1], prices[i] - buy);
        // }
        // int sell = prices[n-1];
        // int ans = day1[n-1];
        // for(int i=n-2; i>=0; i--){
        //     sell = max(sell, prices[i]);
        //     day2[i] = max(day2[i+1], sell - prices[i]);
        //     ans = max(ans, day1[i] + day2[i]);
        // }
        // return ans;
        
        int oneBuyOneSell = 0, twoBuyTwoSell = 0;
        int oneBuy = INT_MAX, twoBuy = INT_MAX;
        for(auto x: prices){
            oneBuy = min(oneBuy, x);
            oneBuyOneSell = max(oneBuyOneSell, x - oneBuy);
            twoBuy = min(twoBuy, x - oneBuyOneSell);
            twoBuyTwoSell = max(twoBuyTwoSell, x - twoBuy);
        }
        return twoBuyTwoSell;
        //3, 0, 3, 0 // 3, 0, 3, 0// 3, 2, 3, 2//0, 2, -2, 2//0, 2, -2, 2//0, 3, -2, 5
        
        // Here, the oneBuy keeps track of the lowest price, and oneBuyOneSell keeps track of the biggest profit we could get.
        // Then the tricky part comes, how to handle the twoBuy? 
        // Suppose in real life, you have bought and sold a stock and made $100 dollar profit. 
        // When you want to purchase a stock which costs you $300 dollars, how would you think this? 
        // You must think, um, I have made $100 profit, so I think this $300 dollar stock is worth $200 FOR ME since I have hold $100 for free.
        // There we go, you got the idea how we calculate twoBuy!! We just minimize the cost again!! 
        // The twoBuyTwoSell is just making as much profit as possible.
        
    }
};