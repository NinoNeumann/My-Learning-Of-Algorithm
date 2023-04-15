//
// Created by Nino Neumann on 2023/4/15.
//
#include<iostream>
#include<queue>
using namespace std;


int main(){
    priority_queue<int,vector<int>,greater<int>> heap;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i<n;++i){
        int t;
        scanf("%d",&t);
        heap.push(t);
    }
    while(m--){
        printf("%d ",heap.top());
        heap.pop();
    }


    return 0;
}