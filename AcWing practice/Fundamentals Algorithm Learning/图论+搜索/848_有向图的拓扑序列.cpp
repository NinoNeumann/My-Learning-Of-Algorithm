//
// Created by Nino Neumann on 2023/3/5.
//
// 算法思路
/*
 * 将所有的入度为0 的点入队
 *  while 队列不空
 *      t 当前队头节点
 *      枚举t的所有出边的节点 例如j
 *          将j的出度--
 *          if dj(j的出度==0) 将j节点入队
 * */

#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

const int N = 1e5+10;


struct head{
    vector<int> chain;
};

head g[N];
int n,m;
int d[N];
vector<int> res_seq;


void dfs(){
    queue<int> q;
    // 将所有出度为0 的节点入队
    for(int i = 1;i<=n;++i){
        if(!d[i])q.push(i);
    }
    while(!q.empty()){
        int t = q.front();
        q.pop();
        res_seq.push_back(t);
        for(auto x:g[t].chain){
            d[x]--;
            if(!d[x]) q.push(x);
        }
    }


}

int main(){
    cin>>n>>m;
    for(int i = 0;i<m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        d[y]++;
        g[x].chain.push_back(y);
    }
    dfs();
    if(res_seq.size()!=n)
        cout<<"-1";
    else
        for(auto x:res_seq)cout<<x<<" ";
    return 0;
}
//
//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//const int N = 100010;
//vector<int> graph[N];
//vector<int> res;
//int ind[N]; // 记录节点入度；
//int n,m;
//
//
//void top_sort(){
//    queue<int> q;
//    for(int i = 1;i <= n; ++ i){
//        if(!ind[i])
//            q.push(i);
//    }
//    while(!q.empty()){
//        int x = q.front();
//        res.push_back(x);
//        q.pop();
//        for(auto y:graph[x]){
//            if((--ind[y])==0)
//                q.push(y);
//        }
//    }
//
//}
//int main(){
//    cin>>n>>m;
//    for(int i = 0;i<m;++i){
//        int x,y;
//        cin>>x>>y;
//        graph[x].push_back(y);
//        ind[y]++;
//    }
//
//    top_sort();
//    if(res.size()==n)
//        for(auto x:res)
//            cout<<x<<' ';
//    else
//        cout<<-1;
//    return 0;
//}

