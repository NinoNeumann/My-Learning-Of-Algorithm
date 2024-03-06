//
// Created by Nino Neumann on 2024/3/6.
//
//


/**
 *
 * 思路：先生成spiral图 然后记录每个点的坐标，bfs找最短路径
 *
 *
 */

#include<iostream>
#include<queue>
using namespace std;

const int N = 10010;
const int M = 103;

typedef pair<int,int> PII;

int Graph[M][M];
bool prime[M];


void take_prime(){
    // 筛除质数 埃氏筛法
    for(int i = 2;i<=102;++i){
        if(!prime[i])
            for(int j = i+i;j<=102;j+=i) prime[j] = true;
    }
}

void bfs()


void generate_graph(){
    int r1 = 9,c2 = 9,c1 = 9,r2 = 9;
    PII r1s = {1,1},r2s = {1,10};
    PII c1s = {10,1},c2s = {10,10};
    for(int i = 10000;i>=1;--i){
        switch (i%4) {
            case 0: {
                //
                for(int j = r1s;j<r1s+r1;++j){
                    Graph[r1]
                }

            }
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
        }

    }



}

int main(){



    return 0;
}