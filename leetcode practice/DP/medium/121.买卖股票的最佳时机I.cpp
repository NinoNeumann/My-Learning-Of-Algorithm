//
// Created by Nino Neumann on 2024/3/3.
//

// 一次遍历寻找数组中最大的前后落差
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = 0x3f3f3f3f;
        int profit = 0;
        for(auto p:prices){
            cost = min(cost,p);
            profit = max(profit,p-cost);
        }
        return profit;
    }
};