//
// Created by Nino Neumann on 2023/4/27.
//
#include<iostream>
#include<string>
using namespace std;


const int N = 30;
int n;
int r[N],l[N];
string v[N];
int root;


bool is_leaf(int u){
    return (r[u]==-1) && (l[u]==-1);
}

void dfs(int u){
    if(u==-1) return;
    if(u!=root && !is_leaf(u))cout<<"(";
    dfs(l[u]);
    cout<<v[u];
    dfs(r[u]);
    if(u!=root && !is_leaf(u))cout<<")";
    return ;
}



int main(){
    cin>>n;
    root = (n+1)*n >> 1;
    // cout<<root<<endl;
    for(int i = 1;i<=n;++i){
        string str;
        int lt,rt;
        cin>>str>>lt>>rt;
        v[i] = str,l[i] = lt,r[i] = rt;
        if(lt!=-1) root -= lt;
        if(rt!=-1) root -= rt;
    }
    // cout<<root<<endl;
    dfs(root);



    return 0;
}