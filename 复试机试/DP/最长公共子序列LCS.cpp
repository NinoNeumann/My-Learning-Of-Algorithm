//
// Created by Nino Neumann on 2024/3/1.
//
// 如何记录最长序列的实际值！
#include<iostream>
using namespace std;

const int N = 101;

string f[N][N][N];
string a,b,c;

int main(){
    cin>>a>>b>>c;
    a = ' ' + a;
    b = ' ' + b;
    c = ' ' + c;
    for(int i = 1; i<a.size(); ++ i)
        for(int j = 1; j<b.size(); ++ j){
            for(int k = 1; k<c.size(); ++ k){
                if(a[i]==b[j] && b[j]==c[k])
                    f[i][j][k] = f[i-1][j-1][k-1] + a[i];
                else if(f[i-1][j][k].size()>=max(f[i][j-1][k].size(),f[i][j][k-1].size()))
                    f[i][j][k] = f[i-1][j][k];
                else if(f[i][j-1][k].size()>=max(f[i-1][j][k].size(),f[i][j][k-1].size()))
                    f[i][j][k] = f[i][j-1][k];
                else
                    f[i][j][k] = f[i][j][k-1];
            }
        }
    cout<<f[i-1][j-1][k-1];

    return 0;
}