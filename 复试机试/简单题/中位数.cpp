//
// Created by Nino Neumann on 2024/3/1.
//
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e4+10;
int nums[N];
int main(){
    int n;
    while(cin>>n && n){
        for(int i = 1;i<=n;++i) cin>>nums[i];
        sort(nums+1,nums+1+n);
        if(n%2) cout<<nums[(n>>1)+1]<<endl;
        else cout<<((nums[(n>>1)+1]+nums[n>>1])>>1)<<endl;
    }
    return 0;
}