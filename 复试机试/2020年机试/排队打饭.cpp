//
// Created by Nino Neumann on 2024/3/8.
//

#include "iostream"
using namespace std;

const int N = 1000000;

long long a[N],b[N],c[N];


int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i = 1;i<=n;++i)
        cin>>a[i]>>b[i]>>c[i];
    long long e = a[1]+b[1]; // e记录的是上一个同学结束的时间
    cout<<a[1];
    for (int i = 2; i <= n; ++i) {
        if(e<=a[i]){
            // 上一个同学结束之后这一个同学才到达
            cout<<' '<<a[i];
            e = a[i]+b[i];
        }else if(a[i]+c[i]>=e){
            // 上一个同学的结束打饭时间在这一个同学的忍受范围内
            cout<<' '<<e;
            e += b[i];
        }else{
            cout<<' '<<"-1";
        }
    }
    return 0;
}