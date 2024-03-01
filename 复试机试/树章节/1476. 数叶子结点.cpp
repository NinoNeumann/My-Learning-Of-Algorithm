//
// Created by Nino Neumann on 2024/3/1.
//
#include<iostream>
#include<vector>
using namespace std;

const int N = 200;
// 思路 dfs 将当前层的叶子节点数存放到一个数组中
int leaf[N];
int max_depth;
vector<int> tree[N];
void dfs(int root,int depth){
    if(!tree[root].size()){
        leaf[depth]++;
        max_depth = max(max_depth,depth);
        return;
    }
    for(auto son:tree[root]){
        dfs(son,depth+1);
    }
    return ;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;++i){
        int id,k;
        cin>>id>>k;
        for(int j = 0;j<k;++j){
            int t;
            cin>>t;
            tree[id].push_back(t);
        }
    }
    dfs(1,0);
    for(int i = 0;i<=max_depth;++i)
        cout<<leaf[i]<<' ';


    return 0;
}