//
// Created by Nino Neumann on 2023/3/1.
//
// 最长递减子序列==最少上升子序列覆盖数量
// 最长递增子序列==最少下降子序列覆盖数量
#include<iostream>
using namespace std;

const int N = 60;

int up[N],down[N]; // 用来存储 上升和下降所有情况的最后一个数字
int a[N];
int ans; // 全局变量存储答案再dfs中不断去更新
int n;
// 每次遇到的数都可以归结为两类：1 加入上升序列 2 加入下降序列
void dfs(int u,int d,int t){
    if(t==n) {
        // 递归到边界了 可以查看当前的状态更新ans
        ans = min(ans,u+d);
        return;
    }
    if(u+d>=ans) return; // 这次迭代的答案要比 前面算出来的答案大了 所以不是最优解。
    // 第一种情况 找上升的
    int i = 1;
    while(i<u && up[i]>=a[t]) i++;
    int tp = up[i];
    up[i] = a[t];
    dfs(max(u,i),d,t+1);
    up[i] = tp;

    i = 1;
    while(i<d && down[i]<=a[t]) ++i
    tp = down[i];
    down[i] = a[t];
    dfs(u, max(d,i),t+1);
    down[i] = tp;
}


int main(){
    while(scanf("%d",&n)!=EOF && n!=0){
        for(int i = 0;i<n;++i) cin >> a[i];
        dfs(0,0,0);
        printf("%d",ans);
    }


    return 0;
}