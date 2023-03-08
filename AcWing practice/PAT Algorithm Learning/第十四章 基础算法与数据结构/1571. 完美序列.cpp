//
// Created by Nino Neumann on 2023/3/8.
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
const int N = 1e5+10;
int num[N];
LL n,p;
int main(){
    cin>>n>>p;
    vector<int> num;
    int mx = n;
    int mn = 0;
    for(int i = 1;i<=n;++i){
        int k;
        cin>>k;
        num.push_back(k);
    }
    sort(num.begin(),num.end());

    while((LL)num[mx-1]>=(LL)num[mn]*p) {
        mx--;
        if((LL)num[mx-1]>=(LL)num[mn]*p)mn++;
    }
    cout<<mx-mn<<endl;




    return 0;
}