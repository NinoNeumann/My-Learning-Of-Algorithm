//
// Created by Nino Neumann on 2023/4/23.
//
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 110;

struct node{
    int w;
    int l,r;
};
int n;
node tree[N];
int v[N];
int cnt;

void inorder(int root){
    if(root==-1)return;
    int l = tree[root].l;
    int r = tree[root].r;
    inorder(l);
    tree[root].w = v[cnt++];
    inorder(r);
}

void bfs(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        auto front = q.front();
        int l_tree = tree[front].l, r_tree = tree[front].r;
        q.pop();
        cout<<tree[front].w<<" ";
        if(l_tree>=0) q.push(l_tree);
        if(r_tree>=0) q.push(r_tree);
    }
}


int main(){

    cin>>n;
    for(int i = 0;i<n;++i)
        cin>>tree[i].l>>tree[i].r;

    for(int i = 0;i<n;++i)cin>>v[i];
    sort(v,v+n);
    inorder(0);
    bfs(0);

    return 0;
}