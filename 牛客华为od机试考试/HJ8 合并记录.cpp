//
// Created by Nino Neumann on 2024/2/22.
//

#include <iostream>
using namespace std;
const int N = 2e7;
int res[N];
// int indx[N],value[N],idx;


int main() {
    int n;
    cin>>n;
    for(int i = 0;i<n;++i){
        int idx,value;
        cin>>idx>>value;
        res[idx]+=value;
    }
    for(int i = 0;i<N;++i){
        if(res[i]){
            cout<<i<<' '<<res[i]<<endl;
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")