//
// Created by Nino Neumann on 2023/4/23.
//
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;


vector<int> odd,even;

bool cmp(int &a,int &b){
    return a>b;
}

int main(){

    int t;
    while(cin>>t){
        // cout<<t<<" ";
        if(t%2) odd.push_back(t);
        else even.push_back(t);

    }
    sort(odd.begin(),odd.end(),cmp);
    sort(even.begin(),even.end());
    for(auto x:odd){
        cout<<x<<" ";
    }
    for(auto x:even){
        cout<<x<<" ";
    }

    return 0;
}