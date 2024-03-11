//
// Created by Nino Neumann on 2024/3/8.
//
#include "iostream"
using namespace std;
const int N = 1e5+10;
const int INF_MIN = 0x8f8f8f8f;
int f[N];
int mx = INF_MIN;
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i = 1; i <= n; ++i){
        cin>>f[i];
        f[i] = max(f[i],f[i-1]+f[i]);
        mx = max(mx,f[i]);
    }
    cout<<mx<<endl;
    return 0;
}
