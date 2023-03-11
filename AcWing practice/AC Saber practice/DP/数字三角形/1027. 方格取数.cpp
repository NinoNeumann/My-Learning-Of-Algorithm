//
// Created by Nino Neumann on 2023/3/11.
//
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

/*
 *
k i1 i2
四种状态枚举：
上 上
上 左
左 上
左 左

倒序：
 下 下  i1+1 j1  i2+1 j2 ==>  i1+1 k+1   i2+1 k+1
 下 右  i1+1 j1  i2 j2+1 ==>  i1+1 k+1   i2   k+1
 右 下
 右 右

*/

const int N = 11;
int f[2*N][N][N];

int main(){
    int n;
    int res = 0;
    cin>>n;
    vector<vector<int>> mp(n+1,vector<int>(n+1,0));
    int x,y,w;
    while(cin>>x>>y>>w, x||y||w) mp[x][y] = w;

    for(int k = 2*n;k>=2;--k){
        for(int i1 = n;i1>=1;--i1){
            for(int i2 = n;i2>=1;--i2){
                int t = mp[i1][k-i1];
                if(i1!=i2) t+= mp[i2][k-i2];
                int &var = f[k][i1][i2];
                var = max(var,f[k+1][i1+1][i2+1]+t);
                var = max(var,f[k+1][i1][i2+1]+t);
                var = max(var,f[k+1][i1+1][i2]+t);
                var = max(var,f[k+1][i1][i2]+t);
//                f[k][i1][i2] = max(var1)
            }
        }
    }
    cout<<f[2][1][1]<<endl;



//    for(int k = 2;k<=2*n;++k)
//        for(int i1 = 1;i1<=n;++i1)
//            for(int i2 = 1;i2<=n;++i2){
//                int j1 = k-i1,j2 = k-i2;
//                if(j1 >=1 && j1 <= n && j2 >= 1 && j2 <= n){
//                    int t = mp[i1][j1];
//                    if(i1 != i2) t += mp[i2][j2];
//                    int &var = f[k][i1][i2];
//                    var = max(var,f[k-1][i1-1][i2-1]+t);
//                    var = max(var,f[k-1][i1-1][i2]+t);
//                    var = max(var,f[k-1][i1][i2-1]+t);
//                    var = max(var,f[k-1][i1][i2]+t);
//                }
//            }
//    cout<<f[2*n][n][n];
    return 0;
}