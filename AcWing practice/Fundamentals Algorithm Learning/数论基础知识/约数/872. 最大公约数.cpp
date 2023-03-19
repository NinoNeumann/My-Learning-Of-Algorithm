//
// Created by Nino Neumann on 2023/3/19.
//
// 欧几里得算法 辗转相除法 求最大公约数
#include<iostream>
using namespace std;

int gcd(int a,int b){
    return b? gcd(b,a%b):a;
}
int n;
int main(){
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        cout<<gcd(a,b)<<endl;
    }
    return 0;
}