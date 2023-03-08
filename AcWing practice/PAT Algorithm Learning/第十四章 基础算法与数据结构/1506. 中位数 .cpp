//
// Created by Nino Neumann on 2023/3/8.
//
//
// N个整数构成的递增序列 中位数是中间位置的数字
// 双指针
#include<iostream>
#include<vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 2e5+10;
int s1[N],s2[N];
int main(){
    int n,m;
    cin>>n;
    for(int i = 0;i<n;++i) cin>>s1[i];
    cin>>m;
    for(int i = 0;i<m;++i) cin>>s2[i];
    int mid = (n+m-1) >> 1;
    // 边界：两个数组长度都是1
    s1[n] = INF;
    s2[m] = INF;
    int p1 = 0, p2 = 0;
    int cnt = 0;
    while(cnt<mid){
        s1[p1]<s2[p2] ? p1++:p2++;
        cnt++;
    }
    cout<<min(s1[p1],s2[p2])<<endl;


}
