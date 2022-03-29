#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int costPrice = prices[0];
        int netProfit = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i] > costPrice){
                netProfit = max(netProfit, prices[i]-costPrice);
            }else{
                costPrice = prices[i];
            }
        }
        return netProfit;
    }
};