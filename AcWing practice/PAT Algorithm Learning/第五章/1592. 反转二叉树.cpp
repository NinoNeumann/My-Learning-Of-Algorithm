//
// Created by Nino Neumann on 2023/4/23.
//
#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 11;

struct node{
    int l,r;
};


node tree[N];
int n;


void reverse_tree(int root){
    if(root==-1) return ;
    reverse_tree(tree[root].l);
    reverse_tree(tree[root].r);
    swap(tree[root].l,tree[root].r);
    return;
}

void bfs(int root){
    // 输出层序遍历
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        auto front = q.front();
        int l = tree[front].l, r = tree[front].r;
        q.pop();
        cout<<front<<" ";
        if(l!=-1) q.push(l);
        if(r!=-1) q.push(r);
    }
    cout<<endl;
}


void inorder(int root){
    if(root==-1) return ;
    inorder(tree[root].l);
    cout<<root<<" ";
    inorder(tree[root].r);
}



int main(){

    cin>>n;
    int root = (n-1)*n >> 1;
    for(int i = 0;i<n;++i){
        char l,r;
        cin>>l>>r;
        if(l!='-'){
            tree[i].l = l-'0';
            root -= (l-'0');
        }else
            tree[i].l = -1;
        if(r!='-'){
            tree[i].r = r-'0';
            root -= (r-'0');
        } else
            tree[i].r = -1;
    }
    reverse_tree(root);

    bfs(root);
    inorder(root);

    return 0;
}
