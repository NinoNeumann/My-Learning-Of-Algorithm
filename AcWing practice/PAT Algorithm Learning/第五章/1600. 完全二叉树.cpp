//
// Created by Nino Neumann on 2023/4/23.
//
#include<iostream>
#include<cstring>
using namespace std;

const int N = 22;
const int M = 5000;

struct node{
    int r,l;
};

node tree[N];
int tree_board[M];
int n;

void dfs(int root,int root_tree_board){

    if(root==-1) return;
    int l = tree[root].l,r = tree[root].r;
    dfs(l,root_tree_board<<1);
    dfs(r,(root_tree_board<<1) + 1);
    tree_board[root_tree_board] = root;
}



int main(){
    cin>>n;
    int root = (n-1)*n >> 1;

    memset(tree_board,-1,sizeof tree_board);
    for(int i = 0;i<n;++i){
        string l,r;
        cin>>l>>r;
        if(l[0]!='-'){
            int w = stoi(l);
            tree[i].l = w;
            root -= w;

        }else tree[i].l = -1;
        if(r[0]!='-'){
            int w = stoi(r);
            tree[i].r = w;
            root -= w;
        }else tree[i].r = -1;
        // cout<<root<<endl;
    }

    // cout<<root<<endl;
    dfs(root,1);
    for(int i = 1;i<=n;++i){
        if(tree_board[i]==-1){
            cout<<"NO "<<root<<endl;
            return 0;
        }
        // cout<<tree_board[i]<<" ";
    }

    cout<<"YES "<<tree_board[n]<<endl;



    return 0;
}