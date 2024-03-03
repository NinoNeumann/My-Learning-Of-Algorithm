//
// Created by Nino Neumann on 2024/3/3.
//
// 如何定义状态 买卖时候的状态只有两种 当前有股票 当前没有股票，并且状态转移只需要看前一天
class Solution {
public:
    // int f[30][2];
    int maxProfit(vector<int>& prices) {
        // 为什么转移的时候只需要对比前一天 即在 当天卖出
        vector<vector<int>> f(prices.size(),vector<int>(2));
        int n = prices.size();
        // 初试状态！
        f[0][1] = -prices[0];
        // f[0][0] = 0;
        for(int i = 1;i<n;++i){
            f[i][0] = max(f[i-1][1]+prices[i],f[i-1][0]);
            f[i][1] = max(f[i-1][0]-prices[i],f[i-1][1]);
        }
        return f[n-1][0];

    }
};