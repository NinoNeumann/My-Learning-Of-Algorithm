//
// Created by Nino Neumann on 2024/3/10.
//
#include "iostream"
#include "cstring"
using namespace std;

const int N = 301;
int s[N];
int f[N][N];
int n;

int main(){
    memset(f,0x3f,sizeof f);
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        cin>>s[i];
        f[i][i] = 0;
        s[i] += s[i-1];
    }

    // 按照区间长度枚举
    for (int len = 2; len <= n; ++len) {
        // 枚举区间左端点
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            // f[i][j] = 0x3f3f3f3f; // 可以选择在循环中初始化点 ，也可以先初始化所有点然后将fii 对角线点初始化为0
            for (int k = i; k < j; ++k) {
                f[i][j] = min(f[i][j],f[i][k] + f[k+1][j] + s[j] - s[i-1]);
            }
        }
    }
    cout<<f[1][n]<<endl;
    return 0;
}