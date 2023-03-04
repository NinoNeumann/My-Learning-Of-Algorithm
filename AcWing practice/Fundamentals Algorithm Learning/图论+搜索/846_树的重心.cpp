//
// Created by Nino Neumann on 2023/3/2.
// 树的遍历：DFS BFS
// 有向图如何遍历  树属于图所以掌握图的DFS BFS；
// 不同形式表示的图（例如二元组表示的树结构和二维数组表示的网状图结构）
// 无论是DFS还是BFS 都需要存在一个东西记录已经遍历过的状态。 DFS中存在状态的回溯
// 树的深度优先遍历可以快速地算出子树的大小
#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5+10;
// 既然是树/图 首先考虑图的存储结构  图的邻接表存储
// 存储部分的思路：
//    1、 看输入的是啥 ： 图 ：给的是 a节点编号-b节点编号  表示a b相邻
//        看输入有无内在顺序：无 编号顺序全随机
//        看是否可以直接用二维数组表示：否 给定的n的范围会导致MLE
//    2、 邻接表表示
//          邻接表的基本组成：表头 和 表头后面的 串 （试着用vector  可行！！）

// 算法思路：
//      1、遍历图中的所有节点 计算出其子树的sum 保存其子树中的最大值

struct head{
    vector<int> chain;
};
head tree[N];
int ans = N;
bool st[N];
int n;

int dfs(int u){
    // u表示当前为编号为u的节点 整个函数即为计算去除u节点后剩余各个子树中的点数最大值
    int s = 1; // 这是包含u自己的点
    int res = 0;
    st[u] = true;
    for(auto x:tree[u].chain){
        if(!st[x]){
            int sub_sum = dfs(x);
            res = max(res,sub_sum); // 在这里，res将计算出当前u节点的所有子树的节点数 res对所有的子树的节点数取最大值
            s+=sub_sum;
        }

    }
    // s 计算得到当前以u为根的子树的节点数
    res = max(res,n-s);  //计算所有的联通块中最大的联通子图节点数  n-s是u的父节点那边的联通子图的节点数
    ans = min(res,ans);  // 所有取重心方案中的大的最小的最大联通子图节点数。
    return s;

}


int main(){
//    memset(st,-1,sizeof st);
    cin>>n;
    for(int i = 1;i<=n;++i){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        tree[t1].chain.push_back(t2);
        tree[t2].chain.push_back(t1);
    }

//    for(int i = 1;i<=n;++i)
    dfs(1);
    cout<<ans<<endl;
    return 0;
}