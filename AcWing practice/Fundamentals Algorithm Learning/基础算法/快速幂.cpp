//
// Created by Nino Neumann on 2023/3/1.
//

#include<iostream>
using namespace std;
typedef long long LL;

LL qmi(int a,int k,int q){
    // a^k mod q
    LL res = 1;
    while(k){
        if(k&1) res = res * (LL) a %q;
        a = (LL) a * a % q;
        k >>= 1;
    }
    return res;
}




int main(){

    return 0;
}