//
// Created by Nino Neumann on 2023/3/29.
//
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;


vector<int> convert(int a,int ridx){
    // 十进制到ridx进制
    vector<int> res;
    if(a==0){
        res.push_back(0);
        return res;
    }
    while(a){
        res.push_back(a%ridx);
        a/=ridx;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    int n,d;
    cin>>n>>d;
    vector<int> cot = convert(n,d);
    bool flag = true;
    for(int i = 0;i<cot.size()/2;++i){
        if(cot[i]!=cot[cot.size()-i-1]){
            flag = false;
            break;
        }
    }

    if(flag)
        cout<<"Yes\n";
    else
        cout<<"No\n";

    for(auto x:cot){
        cout<<x<<" ";
    }

    return 0;
}