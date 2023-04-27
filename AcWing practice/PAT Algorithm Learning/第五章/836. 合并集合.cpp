//
// Created by Nino Neumann on 2023/4/27.
//
#include<iostream>
using namespace std;

const int N = 1e5+10;

int mp[N];

int n,m;

int find_f(int s){
    if(mp[s]!=s) mp[s] =  find_f(mp[s]);
    return mp[s];
}

void merge(int a,int b){
    int fa = find_f(a), fb = find_f(b);
    mp[fa] = fb;

}

int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;++i) mp[i] = i;
    while(m--){
        char c;
        int a, b;
        cin>>c>>a>>b;
        if(c=='M'){
            merge(a,b);
        }else{
            if(find_f(a)==find_f(b)){
                cout<<"Yes\n";
            }else {
                cout<<"No\n";
            }
        }
    }


    return 0;
}
