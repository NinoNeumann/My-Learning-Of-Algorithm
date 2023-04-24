//
// Created by Nino Neumann on 2023/4/24.
//
#include<iostream>
using namespace std;

const int N = 50;

int pre[N],post[N];
int n;


int dfs(int l1,int r1,int l2,int r2,string &in){
    if(l1>r1) return 1;  // 这里表示当前的前序序列是个空序列  空序列也合法。
    if(pre[l1]!=post[r2]) return 0;

    int cnt = 0;// 记录当前节点中的所有合法方案数量
    for(int i = l1;i<=r1;++i){
        string lin,rin;
        int lcnt = dfs(l1+1,i,l2,l2+i-l1-1,lin);
        int rcnt = dfs(i+1,r1,l2+i-l1,r2-1,rin);
        if(lcnt*rcnt){
            cnt += lcnt*rcnt;
            in = lin+to_string(pre[l1])+' '+rin;
            if(cnt>1) break; // 剪枝优化，只有唯一的解法才能不会break。如果这里直接break会使得有多种解法的序列也返回1
        }
    }
    return cnt;
}

int main(){
    cin>>n;

    for(int i = 0;i<n;++i) cin>>pre[i];
    for(int i = 0;i<n;++i) cin>>post[i];

    string inorder;
    int cnt = dfs(0,n-1,0,n-1,inorder);
    // cout<<cnt<<endl;
    if(cnt<=1)puts("Yes");
    else puts("No");
    inorder.pop_back();
    cout<<inorder<<endl;


    return 0;
}