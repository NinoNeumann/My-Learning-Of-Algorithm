//
// Created by Nino Neumann on 2023/4/15.
//
#include<iostream>
using namespace std;
int res_max,res_min;

int main(){
    int n;
    scanf("%d",&n);
    res_min = 0;
    res_max = 1e9+100;
    for(int i = 0;i<n;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        res_max = min(a/b,res_max);
        res_min = max(a/(b+1)+1,res_min);

    }
    printf("%d %d",res_min,res_max);


    return 0;
}