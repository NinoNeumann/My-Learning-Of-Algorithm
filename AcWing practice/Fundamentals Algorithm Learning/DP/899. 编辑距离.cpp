//
// Created by Nino Neumann on 2024/2/28.
//
#include<iostream>
using namespace std;

const int N = 1010;

string strs[N];
string queries;
int f[11][11];
int n,m;

int edit_distance(string a,string b){
    a = ' ' + a;
    b = ' ' + b;
    for(int i = 1;i<a.size();++i){
        for(int j = 1;j<b.size();++j){
            f[i][j] = min(min(f[i-1][j]+1,f[i][j-1]+1),f[i-1][j-1]+!(a[i]==b[j]));
        }
    }
    return f[a.size()-1][b.size()-1];
}


int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;++i)
        cin>>strs[i];
    for(int i = 0;i<=10;++i)f[i][0] = i,f[0][i] = i;

    while(m--){
        int k,res = 0;
        cin>>queries>>k;
        for(int i = 1;i<=n;++i){
            if(edit_distance(strs[i],queries)<=k)res++;
        }
        cout<<res<<endl;
    }

    return 0;
}