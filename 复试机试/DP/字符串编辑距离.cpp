//
// Created by Nino Neumann on 2024/3/1.
//
#include<iostream>
using namespace std;

const int  N = 1e4+10;
string a,b;
int f[N][N];

int main(){
    cin>>a>>b;
    int i,j;
    a = ' ' + a;
    b = ' ' + b;
    for(int i = 1;i<a.size();++i) f[i][0] = i;
    for(int i = 1;i<b.size();++i) f[0][i] = i;
    for(i = 1;i < a.size();++i){
        for(j = 1;j < b.size();++j){
            f[i][j] = min(min(f[i-1][j]+1,f[i][j-1]+1),f[i-1][j-1]+(a[i]==b[j]?0:1));
        }
    }
    cout<<f[a.size()-1][b.size()-1];
    return 0;
}
