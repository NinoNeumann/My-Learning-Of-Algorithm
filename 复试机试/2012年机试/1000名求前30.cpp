//
// Created by Nino Neumann on 2024/3/3.
//
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// 给定十个元素求前三个
const int N = 1e5+10;

int nums[N];
priority_queue<int,vector<int>,greater<int>> heap_less; // 小根堆

int main(){
    ios::sync_with_stdio(false);
    int n,k; // 表示取出最小的前几个
    cin>>n>>k;
    for(int i = 0;i<n;++i){
        cin>>nums[i];
        heap_less.push(nums[i]);
    }
    while(k--){
        cout<<heap_less.top()<<' ';
        heap_less.pop();
    }
    return 0;
}

