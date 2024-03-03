class Solution {
public:
    bool f[101][101];
    bool isInterleave(string s1, string s2, string s3) {
        // f ij 表示 s1的前i个元素 和 s2 的前j个元素 能否组成s3的前i+j个元素
        // 状态转移 如果s1的第i个字母和s3的最后一个相同 则当前状态由上一个即 fi-1 j 决定
        // 同理对于s2一样
        // 如果都不相同则为false
        memset(f,0,sizeof f);
        int n = s1.size();
        int m = s2.size();
        if(n+m != s3.size()) return false;
        s1 = ' ' + s1;
        s2 = ' ' + s2;
        s3 = ' ' + s3;
        f[0][0] = true;
        // 初始化
        for(int i = 1;i<=n && f[i-1][0];++i) f[i][0] = (s1[i]==s3[i]);
        for(int i = 1;i<=m && f[0][i-1];++i) f[0][i] = (s2[i]==s3[i]);
        // 状态转移
        for(int i = 1;i<=n;++i){
            for(int j = 1;j<=m;++j){
                if(s1[i]==s3[i+j]) f[i][j] |= f[i-1][j];
                if(s2[j]==s3[i+j]) f[i][j] |= f[i][j-1]; // 需要考虑当si 可以的时候 sj不行则计算出的两个f直接或就ok
                // 如果两个都是true 取一个true
            }
        }
        return f[n][m];
    }
};