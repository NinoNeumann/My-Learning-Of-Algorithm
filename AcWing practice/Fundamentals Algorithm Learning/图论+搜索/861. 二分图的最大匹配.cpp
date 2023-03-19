//
// Created by Nino Neumann on 2023/3/17.
//
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int N = 550;
const int M = 1e5+10;

struct head{
    vector<int> edges;
}heads[N];

bool st[N];
int match[N];

int n1,n2,m;

bool find(int x){
    for(auto e:heads[x].edges){
        if(!st[e]){
            st[e] = true;
            if(!match[e] || find(match[e])){
                match[e] = x;
                return true;
            }
        }
    }
    return false;
}


int main(){
    cin>>n1>>n2>>m;
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        heads[a].edges.push_back(b);
    }
    int res = 0;
    for(int i = 1;i<=n1;++i){
        memset(st,0,sizeof st);
        if(find(i)) res++;
    }

    cout<<res<<endl;

    return 0;
}




