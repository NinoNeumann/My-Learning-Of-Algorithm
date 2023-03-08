//
// Created by Nino Neumann on 2023/3/8.
//
#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e4+10;

short f[N][N]; // 定义 fij a的以第i个char结尾的 和 b的以第j个char结尾的 构成的公共子串  数值：长度的最大值
string a,b;

int main(){
    cin>>a;
    cin>>b;
    a = ' '+a;
    b = ' '+b;
    short mx = 0;
    for(int i = 1;i<a.length();++i){
        for(int j = 1;j<b.length();++j){
            if(a[i]==b[j] && a[i]>='a' && a[i]<='z') f[i][j] = (f[i][j]>f[i-1][j-1]+1?f[i][j]:f[i-1][j-1]+1);
            mx = (mx>f[i][j]?mx:f[i][j]);
        }
    }
    cout<<mx<<endl;

    return 0;
}
