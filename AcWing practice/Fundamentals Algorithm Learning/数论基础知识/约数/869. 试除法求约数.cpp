//
// Created by Nino Neumann on 2023/3/19.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;


vector<int> get_divisors(int x){
    vector<int> res;
    for(int i = 1;i<=x/i;++i){
        if(x%i==0){
            res.push_back(i);
            if(x/i!=i)
                res.push_back(x/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}

int main(){
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        vector<int> res = get_divisors(x);
        for(auto k:res){
            cout<<k<<" ";
        }
        cout<<endl;
    }

    return 0;
}
