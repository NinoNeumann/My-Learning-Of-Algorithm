//
// Created by Nino Neumann on 2023/4/27.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

const int N = 110;

int w[N];
struct node{
    int id,w;
    bool operator<(node &a) const{
        return w>=a.w;
    }
};
vector<int> path;
vector<node> head[N];
vector<vector<int>> res;

int n,m,s;

bool cmp(string a,string b){
    return a>b;
}

void dfs(int root,int weight){
    if(weight>s) return;
    if(head[root].size()==0){
        if((weight+w[root])==s){
            res.push_back(path);
        }
        return;
    }

    for(auto x:head[root]){
        int son = x.id;
        path.push_back(w[son]);
        dfs(son,weight + w[root]);
        path.pop_back();
    }

}

int main(){
    cin>>n>>m>>s;

    for(int i = 0;i<n;++i) cin>>w[i];
    for(int i = 0;i<m;++i){
        int id,k;
        cin>>id>>k;
        for(int i = 0;i<k;++i){
            int t;
            cin>>t;
            head[id].push_back({t,w[t]});
            // cout<<t<<" ";
        }
        // cout<<endl;
    }

    // for(auto x:head[0]) cout<<w[x]<<

    path.push_back(w[0]);
    dfs(0,0);
    sort(res.begin(),res.end(),greater<vector<int>>());
    for(auto x:res){
        for(auto o:x)cout<<o<<" ";
        cout<<endl;
    }


    return 0;
}
