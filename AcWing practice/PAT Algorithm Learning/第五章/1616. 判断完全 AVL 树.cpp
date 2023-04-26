//
// Created by Nino Neumann on 2023/4/26.
//
#include<iostream>
#include<queue>
using namespace std;


const int N = 30;
bool st[4000];

struct node{
    int v,r,l,h;
};
node tree[N];

int idx;

void update(int u){
    int l = tree[u].l,r = tree[u].r;
    tree[u].h = max(tree[l].h,tree[r].h)+1;
    return;
}

void R(int &u){
    int p = tree[u].l;
    tree[u].l = tree[p].r, tree[p].r = u;
    update(u),update(p);
    u = p;
}

void L(int &u){
    int p = tree[u].r;
    tree[u].r = tree[p].l,tree[p].l = u;
    update(u),update(p);
    u = p;
}


int getbalance(int u){
    return tree[tree[u].l].h - tree[tree[u].r].h;
}


void insert(int &u,int v){

    if(!u){
        u = ++idx;
        tree[u].v = v;
    }
    else if(tree[u].v<=v){
        insert(tree[u].r,v);
        if(getbalance(u)==-2){
            if(getbalance(tree[u].r)==1) R(tree[u].r);
            L(u);
        }
    }else {
        insert(tree[u].l,v);
        if(getbalance(u)==2){
            if(getbalance(tree[u].l)==-1) L(tree[u].l);
            R(u);
        }
    }
    update(u);
}


void dfs(int root,int pos){
    // pos 从0 开始
    if(!root) return;

    st[pos] = true;
    dfs(tree[root].l,pos<<1);
    // cout<<tree[root].v<<endl;
    dfs(tree[root].r,(pos<<1) + 1);
}

void bfs(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        cout<<tree[f].v<<" ";
        if(tree[f].l) q.push(tree[f].l);
        if(tree[f].r) q.push(tree[f].r);
    }
}

int main(){
    int root = 0;
    int v,n;
    bool flag = true;
    cin>>n;
    for(int i = 0;i<n;++i){
        cin>>v;
        insert(root,v);
        // cout<<v<<" ";
    }

    dfs(root,1);
    bfs(root);
    cout<<endl;
    for(int i = 1;i<=n;++i){
        if(!st[i]){
            flag=false;
            break;
        }
        // cout<<st[i];
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}





