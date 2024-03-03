//
// Created by Nino Neumann on 2024/3/3.
//
#include<iostream>
using namespace std;

const int N = 1000;

int l[N],r[N];
int res;

int dfs(int root){ // 返回值是最大叶子节点的间距
    // 计算当前节点到左 右 子树叶子节点的距离
    int t_l = 0;
    int t_r = 0;
    if(l[root]!=-1) t_l = dfs(l[root])+1;
    if(r[root]!=-1) t_r = dfs(r[root])+1;
    // 此时t_l是当前节点到左子树最远的叶子节点的距离 同理t_r;
    if(t_l && t_r) res = max(res,t_l+t_r); // 只有当左右子树都有叶子节点的时候才会计算叶子节点间距
    // 考虑到了一种特殊情况 就是只有一排的树 这时候叶子间距为0？
    /*
     * 0
     *  \
     *   1
     *    \
     *     2
     * */
    // 后序遍历中处理左右子树的最大叶子间距 找最大值
    return max(t_l,t_r);

}

int main(){
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
        for(int i = 0;i<n;++i) cin>>l[i]>>r[i];
        dfs(0);
        cout<<res<<endl;
    }
    return 0;
}