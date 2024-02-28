//
// Created by Nino Neumann on 2024/2/22.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    scanf("%d",&n);
    for(int i = 2;i<=n/i;++i){
        if(n%i==0){
            while(n%i==0){
                n/=i;
                printf("%d ",i);
            }
        }
    }
    if (n != 1) {
        printf("%d ", n);
    }
}
// 64 位输出请用 printf("%lld")
// 一定要注意在最后要判定 if (n != 1)这个条件 否则会漏掉数据
