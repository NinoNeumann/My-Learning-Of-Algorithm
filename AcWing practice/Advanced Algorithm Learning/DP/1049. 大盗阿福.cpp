//
// Created by Nino Neumann on 2023/3/17.
//
#include<iostream>
#include<cstring>
using namespace std;


const int N = 1e5+10;
int f[N];  // fi 表示前i家的合法偷取方案的集合  属性是偷取值的最大值
int g[N];
int t,n;


int main(){
    cin>>t;
    while(t--){
        cin>>n;
        memset(f,0,sizeof f);

        for(int i = 1;i<=n;++i)scanf("%d",&g[i]);

        if(n==1){
            cout<<g[1]<<endl;
            continue;
        }

        f[1] = g[1];
        for(int i = 2;i<=n;++i){
            // 对于每一个状态fi 都有前i-2个状态需要考虑
            f[i] = f[i-1];
            f[i] = max(f[i-1],f[i-2]+g[i]);
//            for(int j = 0;j<=i-2;++j){
//                f[i] = max(f[i],f[j]+g[i]);
//            }
        }
        cout<<f[n]<<endl;

    }


    return 0;
}


