//
// Created by Nino Neumann on 2023/3/3.
//
// redo
//  1、状态表示 fij 表示在j的体积下 将前i个物品装入背包的所有选择
//  2、状态计算 fij = max(fi-1 j-vi + wi or fi-1 j)  推导过程 ：当前状态看是由上一个状态  即  装或者不装第i个物品 而来的

#include<iostream>
using namespace std;
const int N = 1010;

int f[N][N],v[N],w[N];
int n,m; // m最大容积


int main(){
    // 输入输出
    cin>>n>>m;
    for(int i = 1;i<=n;++i) cin>>v[i]>>w[i];

    // 状态计算
    // 对于每种状态  首先最外层循环遍历当前所有的物品
//    for(int i = 1;i<=n;++i){
//        // 对于个物品又有j种不同的背包容量
//        for(int j = 1;j<=m;++j){
//            // 如果当前背包装的下当前的物品那么就进行状态计算
//            if(j>=v[i]) f[i][j] = max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
//            else f[i][j] = f[i-1][j];
//        }
//    }
    // 降低维度优化空间：
    for(int i = 1;i<=n;++i)
        for(int j = m;j>=v[i];j--){
            f[j] = max(f[j],f[j-v[i]]+w[i]);  // 因为这里的fi 需要由 fj-v 的参与如果 j从小开始循环那么fj-v将不会是一个被计算出来的数
        }
    cout<<f[n][m]<<endl;

    return 0;
}
