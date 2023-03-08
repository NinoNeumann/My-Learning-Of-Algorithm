//
// Created by Nino Neumann on 2023/3/8.
//
// 输入3个子串， 输出这3个子串的最大公共子串
// fijk
#include<iostream>
#include<cstring>
using namespace std;


const int N = 1e2+10;

int f[N][N][N];


int main(){
    int n ;
    cin>>n;
    string a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    a = ' ' + a;
    b = ' ' + b;
    c = ' ' + c;
    int mx = 0;
    for(int i = 1;i<a.length();++i){
        for(int j = 1;j<b.length();++j){
            for(int k = 1;k<c.length();++k){
                if(a[i]==b[j] && b[j]==c[k]) f[i][j][k] = max(f[i][j][k],f[i-1][j-1][k-1]+1);
//                cout<<f[i][j][k]<<endl;
                mx = max(mx,f[i][j][k]);
            }
        }
    }
    cout<<mx<<endl;

    return 0;
}