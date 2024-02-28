//
// Created by Nino Neumann on 2023/5/6.
//
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
// 题目大意：给你后续和中序遍历 请你写出层序遍历

const int N = 33;

int postorder[N],inorder[N];
int n;
unordered_map<int,int> pos,l,r; // 记录 中序遍历中数字和位置的对应关系

int build(int il,int ir,int pl,int pr){
    int root = postorder[pr];
    int k = pos[root];
    if(k>il) l[root] = build(il,k-1,pl,pl+k-1-il);
    if(k<ir) r[root] = build(k+1,ir,pl+k-il,pr-1);
    return root;
}

string bfs(int root){
    // 要求最后没有多余空格
    queue<int> q;
    string res;
    q.push(root);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        res = res+to_string(t)+' ';
        if(l.count(t)!=0) q.push(l[t]);
        if(r.count(t)!=0) q.push(r[t]);
    }
    res.pop_back();
    return res;
}

int main(){
    cin>>n;
    for(int i = 0;i<n;++i) cin>>postorder[i];
    for(int i = 0;i<n;++i){
        cin>>inorder[i];
        pos[inorder[i]] = i;
    }
    int root = build(0,n-1,0,n-1);
    string res = bfs(root);
    cout<<res<<endl;

    return 0;
}


