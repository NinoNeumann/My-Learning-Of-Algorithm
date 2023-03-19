//
// Created by Nino Neumann on 2023/3/19.
//
#include<iostream>
#include<unordered_map>
using namespace std;

typedef long long LL;

const int mod = 1e9+7;

int n;


int main(){
    cin>>n;
    unordered_map<int,int> primes;
    while(n--){
        int x;
        cin>>x;
        for(int i = 2;i<=x/i;++i){
            while(x%i==0){
                x/=i;
                primes[i]++;
            }
        }
        if(x>1) primes[x]++;
    }

    LL res = 1;
    for(auto prime:primes){
        int p = prime.first,a = prime.second;
        LL t = 1;
        while(a--) t = (p*t+1) % mod;
        res = res * t % mod;
    }

    cout<<res<<endl;


    return 0;
}
