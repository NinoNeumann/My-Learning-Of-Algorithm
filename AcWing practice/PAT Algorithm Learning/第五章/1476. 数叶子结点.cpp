//
// Created by Nino Neumann on 2023/4/18.
//
#include<iostream>
#include<vector>

using namespace std;

const int N = 1e2+10;

vector<int> heads[N];
int leaf_nums[N];
int max_depth;


int n,m;

void dfs(int u,int depth){
    if(heads[u].empty()){
        max_depth = max(max_depth,depth);
        leaf_nums[depth]++;
        return ;
    }

    for(auto x:heads[u])
        dfs(x,depth+1);

    return;

}


int main(){

    cin>>n>>m;
    for(int i = 0;i<m;++i){
        int k,id;
        cin>>id>>k;
        while(k--){
            int d;
            cin>>d;
            heads[id].push_back(d);
        }
    }

    // 遍历所有的节点

    dfs(1,0);
    // cout<<max_depth<<endl;
    cout<<leaf_nums[0];
    for(int i = 1;i<=max_depth;++i){
        cout<<" "<<leaf_nums[i];
    }

    return 0;
}