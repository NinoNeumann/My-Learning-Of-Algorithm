//
// Created by Nino Neumann on 2023/3/19.
//
#include<iostream>
#include<unordered_map>
using namespace std;



int n;
typedef long long LL;
const int mod = 1e9+7;



int main(){
    cin>>n;
    unordered_map<int,int> primes;
    while(n--){
        int x;
        cin>>x;
        // 首先对于输入的数进行算数基本定理的分解
        for(int i = 2;i<=x/i;++i)
            while(x%i==0){
                x/=i;
                primes[i]++;
            }
        if(x>1) primes[x]++;
    }
    LL res = 1;
    for(auto prime:primes) res = res * (prime.second+1) % mod; // 自乘和取模这边一定要多注意！
    cout<<res<<endl;


    return 0;
}
