//
// Created by Nino Neumann on 2023/3/19.
//
#include<cmath>
#include<iostream>
using namespace std;

int n;

bool is_prime(int x){
    if(x<2)return false;
    for(int i = 2;i<=(int)sqrt(x);++i){
        if(x%i==0) return false;
    }
    return true;
}

int main(){
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(is_prime(x))cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}