//
// Created by Nino Neumann on 2023/4/27.
//
#include<iostream>
#include<vector>
using namespace std;


const int N = 110;

vector<int> heads[N];
int depth[N];
int max_depth,depth_idx;

void dfs(int root,int d){
    depth[d]++;
    if(max_depth<depth[d]) max_depth = depth[d],depth_idx = d;
    if(heads[root].empty()){
        return ;
    }
    for(auto x:heads[root]){
        dfs(x,d+1);
    }
}


int main(){
    int n,m;
    int root = 1;
    cin>>n>>m;
    for(int i = 0;i<m;++i){
        int id,k;
        cin>>id>>k;
        for(int i = 0;i<k;++i){
            int t;
            cin>>t;
            heads[id].push_back(t);
        }
    }

    dfs(root,1);

    cout<<max_depth<<" "<<depth_idx<<endl;
    return 0;
}