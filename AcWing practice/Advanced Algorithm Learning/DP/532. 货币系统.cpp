//
// Created by Nino Neumann on 2023/3/6.
//
// 好思路：求极大线性无关组
//
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;


const int N = 110;
const int M = 25010;
int f[N]; // fi 表示 用前i-1个数字能否表示i

int main(){
    int k;
    cin>>k;
    while(k--){
        int n;
        int res = 0;
        vector<int> a;
        cin>>n;

        for(int i = 0;i<n;++i){
            int t;
            cin>>t;
            a.push_back(t);
        }
        sort(a.begin(),a.end());
        int m = a[a.size()-1];
        memset(f,0,sizeof f);
        f[0] = 1;
        for(auto x:a){
            if(!f[x]) res++;
            for(int j = x;j<=m;++j){
                f[j] |= f[j-x];
            }
        }
        cout<<res<<endl;
    }

    return 0;
}