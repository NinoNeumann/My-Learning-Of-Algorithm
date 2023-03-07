//
// Created by Nino Neumann on 2023/3/6.
//
// 好思路：求极大线性无关组
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


const int N = 110;


int main(){
    int k;
    cin>>k;
    while(k--){
        int n;
        cin>>n;
        vector<int> a;
        for(int i = 0;i<n;++i){
            int t;
            cin>>t;
            a.push_back(t);
        }
        sort(a.begin(),a.end());
        // 对每个数据进行其之前的 dp

    }

    return 0;
}