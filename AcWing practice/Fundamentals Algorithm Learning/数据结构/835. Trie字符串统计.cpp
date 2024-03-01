//
// Created by Nino Neumann on 2024/2/29.
//
#include<iostream>
using namespace std;

const int N = 1e5+10;

int tree[N][26],idx,cnt[N],n;
char s[N];

// 二维数组存储树 模型

void insert(char str[]){
    int p = 0; // 每次查询从根节点开始
    for(int i = 0;str[i];++i){
        int u = str[i] - 'a';
        if(!tree[p][u]) tree[p][u] = ++ idx;
        p = tree[p][u];
    }
    cnt[p]++;
}

int query(char str[]){
    int p = 0;
    for(int i = 0;str[i];++i){
        int u = str[i]-'a';
        if(!tree[p][u]) return 0;
        p = tree[p][u];
    }

    return cnt[p];
}


int main(){
    ios::sync_with_stdio(false);
    cin>>n;

    while(n--){
        char op;
        cin>>op>>s;
        if(op=='I') insert(s);
        else cout<<query(s)<<endl;
    }


    return 0;
}
