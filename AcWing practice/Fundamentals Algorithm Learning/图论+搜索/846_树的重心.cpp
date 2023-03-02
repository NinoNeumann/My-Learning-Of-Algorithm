//
// Created by Nino Neumann on 2023/3/2.
// 树的遍历：DFS BFS
// 有向图如何遍历  树属于图所以掌握图的DFS BFS；
// 不同形式表示的图（例如二元组表示的树结构和二维数组表示的网状图结构）
// 无论是DFS还是BFS 都需要存在一个东西记录已经遍历过的状态。 DFS中存在状态的回溯
// 树的深度优先遍历可以快速地算出子树的大小
#include<iostream>
using namespace std;



const int N = 1e5+10;
const int M = N*2;
// 既然是树/图 首先考虑图的存储结构

bool st[N];

void dfs(int s){
    st[s] = true;
    for(){

    }//遍历s 所能到达的所有节点){

}


int main(){
    memset(st,-1,sizeof st);


    return 0;
}