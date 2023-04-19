//
// Created by Nino Neumann on 2023/4/19.
//
// 判断给出的树是不是一个连通的，如果不是求出连通分量-- 并查集
// 求最深的根：对每个点进行遍历 dfs  存储图用的邻接表需要使用简易的邻接表否则会超时。
#include "iostream"
#include "vector"
#include<cstring>
using namespace std;

const int N=1e4+10,M=N*2;  //
int h[N],e[M],ne[M],idx; //邻接表存稀疏树图

int n,k; // 一共有多少个节点

// 定义并查集以及相关操作
int p[N];

int find(int a){
    if(p[a]!=a) p[a] = find(p[a]);
    return p[a];
}

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

void merge(int a,int b){
    int fa = find(a),fb = find(b);
    p[fa] = fb;
}
// 定义存储树的结构

// struct head{
//     vector<int> e;
// };
// head heads[N];

// dfs
int dfs(int u,int father){
    // 计算当前根的最大深度
    int depth = 0;
    // if(heads[root].e.empty()){   // 搜索到叶子节点了；
    //     return depth;
    // }
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(j==father) continue; //重复搜了
        depth=max(depth,dfs(j,u)+1);
    }

    // for(auto x:heads[root].e){
    //     if(x==father)continue;
    //     depth = max(depth,dfs(x,root)+1);
    // }
    return depth;
}




int main(){

    scanf("%d",&n);
    k=n;
    for(int i = 0;i<=n;++i) p[i] = i;
    memset(h,-1,sizeof h); //初始化邻接表
    for(int i = 0;i<n-1;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        int fx = find(x),fy = find(y);
        if(fx!=fy){
            p[fx] = fy;
            k--;
        }
        add(x,y);add(y,x); //无向边加两次
        // heads[x].e.push_back(y);
        // heads[y].e.push_back(x);
    }
    if(k>1) printf("Error: %d components\n",k);
    else
    {
        vector<int>nodes;
        int max_depth=-1; //设置相反界外量
        for(int i=1;i<=n;i++)
        {
            int depth=dfs(i,-1);  //这个节点无来源点 得到这个点的深度
            if(depth>max_depth)
            {
                max_depth=depth; //更新
                nodes.clear(); //清空
                nodes.push_back(i);
            }
            else if(depth==max_depth) nodes.push_back(i);
        }
        for(auto v:nodes) cout<<v<<endl;

    }


    return 0;
}