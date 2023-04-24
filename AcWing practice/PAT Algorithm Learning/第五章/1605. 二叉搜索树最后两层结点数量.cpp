//
// Created by Nino Neumann on 2023/4/24.
//
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1010;


struct node{
    int depth;
    int w;
    int l,r;
};

node tree[N];
int n,idx;
int max_depth;

// 重点在于理解 idx和insert函数中root使用引用的作用和意义。

// 再插入节点的同时直接标记当前节点的深度。最后由于是一个数组结构体的存储所以只需要遍历所有的数组找到对应深度的节点就可以得出答案
void insert(int &root,int w,int depth){
    if(!root){
        root = ++idx;
        tree[root].w = w;
        tree[root].depth = depth;
        max_depth = max(max_depth,depth); // 记录当前树中的最深节点的深度。
    }
    else if(tree[root].w>=w)
        insert(tree[root].l,w,depth+1);
    else
        insert(tree[root].r,w,depth+1);
}


int main(){
    cin>>n;
    int root = 0;
    int n1 = 0,n2 = 0;

    for(int i = 0;i<n;++i){
        int w;
        cin>>w;
        insert(root,w,0);
    }

    for(int i = 1;i<=n;++i){
        if(tree[i].depth==max_depth) n1++;
        if(tree[i].depth==max_depth-1) n2++;
    }
    cout<<n1<<" + "<<n2<<" = "<<n1+n2<<endl;



    return 0;
}