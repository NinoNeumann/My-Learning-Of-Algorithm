//
// Created by Nino Neumann on 2024/3/2.
//
// 有很强的递归信息！
class Solution {
public:
    int numTrees(int n) {
        // 以i为根节点的二叉搜索树 中的不同二叉搜索树
        // 有序序列中二叉树的个数与其序列中的元素内容无关
        // dpi 长度为i的有序序列组成的二叉搜索树的个数
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        // dp[2] = 2; // 从2可以开始自洽了
        for(int i = 2;i<=n;++i){
            // 枚举当前左子树的大小
            // j = 0  ~~  j = i-1
            // 当前长度为i的可组成的二叉搜索树的个数 =  左子树个数 * 右子树个数
            for(int j = 0;j<i;++j)
                dp[i] += dp[j] * dp[i-j-1];
        }
        return dp[n];
    }
};