#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit, buy_min;
        max_profit = 0;
        buy_min = 101010;
        
        for(int i=0; i<prices.size(); i++) {
            max_profit = max(prices[i] - buy_min, max_profit);
            buy_min = min(buy_min, prices[i]);
        }
        return max_profit;
    }
};