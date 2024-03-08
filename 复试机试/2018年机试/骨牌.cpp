//
// Created by Nino Neumann on 2024/3/7.
//

#include "iostream"
using namespace std;
const int N = 1e6+10;
const int MOD = 999983;
int f[N];

int main(){
    int n;
    cin>>n;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= n; ++i)
        f[i] = (f[i-1] + f[i-2]) % MOD;
    cout<<f[n];
    return 0;
}
