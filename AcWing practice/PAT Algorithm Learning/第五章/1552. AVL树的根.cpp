//
// Created by Nino Neumann on 2023/4/26.
//
#include<iostream>
using namespace std;

const int N = 40;


struct node{
    int v; // 当前节点的权值
    int l,r;  // 左右孩子节点
    int h;  // 当前节点的高度
};
node tree[N]; // 这样记录确实有点不方便
int idx;

void update(int u){
    // 更新节点的高度
    int r = tree[u].r,l = tree[u].l;
    tree[u].h = max(tree[r].h,tree[l].h)+1;
    return;
}


void R(int &u){
    // 右旋 记录根节点的左儿子、 根节点的左儿子=左儿子的右儿子、根节点的左儿子的右儿子=根节点， 节点替换
    int l = tree[u].l;
    tree[u].l = tree[l].r;
    tree[l].r = u;
    update(u),update(l);
    u = l;
}

void L(int &u){
    int r = tree[u].r;
    tree[u].r = tree[r].l, tree[r].l = u;
    update(u),update(r);
    u = r;
}


int getbalance(int u){
    return tree[tree[u].l].h-tree[tree[u].r].h;
}

void insert(int &u,int v){
    // 重点在于弄清楚 四种旋转状态。
    if(!u){  // 很重要的一步！！！；
        u = ++idx;
        tree[u].v = v;
    }else if(tree[u].v<=v){
        // 插入右子树
        insert(tree[u].r,v);
        if(getbalance(u)==-2){
            // 为什么只考虑-2  想想其他的取值的 为不可能或者可能但是不考虑
            if(getbalance(tree[u].r)==1) R(tree[u].r);
            L(u);
        }

    }else{
        // 插入左子树
        insert(tree[u].l,v);
        if(getbalance(u)==2){
            if(getbalance(tree[u].l)==-1) L(tree[u].l);
            R(u);
        }
    }
    update(u);
}


int  main(){
    int n,root = 0;
    cin>>n;
    for(int i = 0;i<n;++i){
        int v;
        cin>>v;
        insert(root,v);
    }

    cout<<tree[root].v<<endl;


    return 0;
}