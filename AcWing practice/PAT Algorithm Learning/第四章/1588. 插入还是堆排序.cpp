//
// Created by Nino Neumann on 2023/4/1.
//
#include<iostream>
#include<queue>
using namespace std;
const int N = 110;

int o[N],af[N];

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;++i) cin>>o[i];
    for(int i = 0;i<n;++i) cin>>af[i];

    int p = 0;
    while(p+1<n && af[p]<af[p+1]) p++;
    int k = p;
    while(k<n && o[k]==af[k]) k++;
    if(k==n){
        cout<<"Insertion Sort\n";
        for(int i = p;i>0;--i){
            if(af[i-1]>af[i]) swap(af[i-1],af[i]);
        }
        for(int i = 0;i<n;++i)
            cout<<af[i]<<" ";
        cout<<endl;
    }else{
        cout<<"Heap Sort\n";
        int g = n-1;
        while(g>0 && af[g]>af[g-1]) g--;
        // 模拟一遍堆排序的down操作


    }


    return 0;
}