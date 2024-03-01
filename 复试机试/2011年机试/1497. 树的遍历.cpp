//
// Created by Nino Neumann on 2024/3/1.
//
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std
const int N = 50;

int inorder[N],postorder[N];
unordered_map<int,int> ltree,rtree,inpos;

int build_tree(int il,int ir,int pl,int pr){
    int root = postorder[pr];
    int root_pos = inpos[root]; // 根节点在中序遍历中的位置
    // 可以进入的条件是什么？inorder中k左侧元素大于等于1 || 起始点下标+实际单位元素个数-1 == 目标下标
    if(root_pos>il) ltree[root] = build_tree(il,root_pos-1,pl,pl+root_pos-il-1);
    if(root_pos<ir) rtree[root] = build_tree(root_pos+1,ir,pl+root_pos-il,pr-1);
    return root;
}
void bfs(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        cout<<f<<' ';
        if(ltree.find(f)!=ltree.end())
            q.push(ltree[f]);
        if(rtree.find(f)!=rtree.end())
            q.push(rtree[f]);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;++i)cin>>postorder[i];
    for(int i = 0;i<n;++i){
        cin>>inorder[i];
        inpos[inorder[i]] = i;
    }
    int root = build_tree(0,n-1,0,n-1);
    bfs(root);
    return 0;
}



