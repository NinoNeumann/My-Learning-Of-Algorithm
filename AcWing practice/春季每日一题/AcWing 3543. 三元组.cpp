//
// Created by Nino Neumann on 2023/4/23.
//
#include<iostream>
using namespace std;

// 三重循环遍历  暴力循环

const int N = 51;

int num[N];

int main(){
    int n;
    cin>>n;
    while(n--){
        int m;
        int cnt = 0;
        cin>>m;
        for(int i = 0;i<m;++i){
            cin>>num[i];
        }

        for(int i = 0;i<m;++i){
            for(int j = 0;j<m;++j){
                for(int k = 0;k<m;++k){
                    if(num[i]+num[j] == num[k]) cnt++;
                }
            }
        }

        cout<<cnt<<endl;

    }

    return 0;
}