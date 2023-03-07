//
// Created by Nino Neumann on 2023/3/7.
//
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

const int N = 12;
const int M = 1<<N;
typedef long long LL;

LL f[N][M];  //  状态表示： fij 表示第从第i-1列伸到第i列的且状态为j的方案数  这里的j使用一个二进制数表示当前列的状态
//vector<int> state;
bool st[M];

int n,m;

int main(){
    while(cin>>n>>m, n||m){
        for(int i = 0;i < 1 << n;++i){
            // 枚举从0~2^n次方中所有的状态 j
            int cnt = 0;
            st[i] = true;
            // 判断是否存在连续的且为偶数个数的0 （在i表示的二进制数中）；
            for(int j = 0;j<n;++j){
                if(i>>j & 1){
                    if(cnt & 1){
                        st[i] = false;
                        break;
                    }
                    cnt = 0;
                }else
                    cnt++;
            }
            if(cnt & 1) st[i] = false;
//            if(st[i]) state.push_back(i);
        }

        memset(f,0,sizeof f);
        f[0][0] = 1;
        for(int i = 1;i<=m;++i){
            // 有可能是两个不合法的状态拼接在一起形成一个合法状态
            for(int j = 0;j< 1<< n;++j){
                for(int k = 0;k< 1<<n;++k){
                    if((j&k)==0 && (st[j|k])) f[i][j] += f[i-1][k];
                }
            }
//            for(auto x:state){
////                f[i][x];
//                for(auto j:state){
//                    if(x&j==0 && st[x|j]){
//                        f[i][x] += f[i-1][j];
//                        cout<<x<<"  "<<j<<"  "<<(x|j)<<endl;
//                    }
//                }
//            }
        }
        cout<<f[m][0]<<endl;
    }


    return 0;
}