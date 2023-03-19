//
// Created by Nino Neumann on 2023/3/19.
//
#include<iostream>
#include<cmath>
using namespace std;

int n;

void divide(int x){

    for(int i = 2;i <= x/i;++i){ // x 中最多只有一个大于根号x的质因子
        if(x%i==0){
            int s = 0;
            while(x%i==0){
                x/=i;
                s++;
            }
            cout<<i<<" "<<s<<endl;
        }
    }
    if(x>1)cout<<x<<" 1\n";
}


int main(){
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        divide(x);
        cout<<endl;
    }
    return 0;
}
