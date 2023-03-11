//
// Created by Nino Neumann on 2023/3/11.
//
#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<vector<int>> mp(n+2,vector<int>(n+2,0));
    vector<vector<int>> f(n+2,vector<int>(n+2,100000));
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            cin>>mp[i][j];
        }
    }
    f[n+1][n] = 0;
    f[n][n+1] = 0;
    for(int i = n;i>=1;--i){
        for(int j = n;j>=1;--j){
            f[i][j] = min(f[i+1][j],f[i][j+1])+mp[i][j];
        }
    }


//    f[1][1] = mp[1][1];
//    for(int i = 1;i<=n;++i){
//        for(int j = 1;j<=n;++j){
//            //第一行和第一列需要特判
//            if(i==1 && j==1) f[i][j] = mp[i][j];// 当到第一个点的时候直接赋值
//            else if(i==1) f[i][j] = min(f[i][j-1]+mp[i][j],f[i][j]); // 第一行
//            else if(j==1) f[i][j] = min(f[i-1][j]+mp[i][j],f[i][j]); // 第一列
//            else f[i][j] = min(f[i-1][j],f[i][j-1])+mp[i][j];       //其余的情况
//        }
//    }

    cout<<f[1][1];
    return 0;
}
