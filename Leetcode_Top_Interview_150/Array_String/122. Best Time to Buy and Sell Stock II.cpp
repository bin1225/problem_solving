#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit, buy;
        profit = 0; buy = prices[0];
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] > buy) {
                profit += prices[i] - buy;
            }
            buy = prices[i];
        }
        return profit;
    }
};