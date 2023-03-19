//
// Created by Nino Neumann on 2023/3/19.
//
#include<iostream>
#include<cmath>
using namespace std;

const int N = 1e6+10;

bool st[N];
int primes[N];


// 朴素筛法
int count_prime(int x){
    int cnt = 0;
    for(int i = 2;i<=x;++i){
        if(!st[i]) cnt++;
        for(int j = i+i;j<=x;j+=i)
            st[j] = true;
    }
    return cnt;
}

// 埃氏筛法
int count_prime(int x){
    int cnt = 0;
    for(int i = 2;i<=x;++i){
        if(!st[i]){
            cnt++;
            for(int j = i+i;j<=x;j+=i)
                st[j] = true;
        }
    }
}
// 线性筛法
int count_prime(int x){
    int cnt = 0;
    for(int i = 2;i<=x;++i){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j]<=x/i;++j){
            st[primes[j]*i] = true;
            if(i % primes[j]==0) break;
        }
    }
    return cnt;
}


int main(){
    int x;
    cin>>x;
    cout<<count_prime(x)<<endl;
    return 0;
}
