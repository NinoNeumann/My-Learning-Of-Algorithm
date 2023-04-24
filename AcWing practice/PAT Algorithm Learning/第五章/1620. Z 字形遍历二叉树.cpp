//
// Created by Nino Neumann on 2023/4/24.
//
#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;


const int N = 40;


int post[N],in[N];
int n,max_depth;
unordered_map<int, int> in_mp,r,l;
vector<int>cnt[N];


int build(int il,int ir,int pl,int pr){
    int root = post[pr];
    int idx = in_mp[root];
    if(il<idx) l[root] = build(il,idx-1,pl,pl+idx-1-il);
    if(idx<ir) r[root] = build(idx+1,ir,pl+idx-il,pr-1);

    return root;
}



void bfs(int root){
    queue<int> q;
    q.push(root);
    string str;
    while(!q.empty()){
        auto t = q.front();
        str = str+to_string(t)+' ';
        q.pop();
        if(l.count(t)) q.push(l[t]);
        if(r.count(t)) q.push(r[t]);
    }
    str.pop_back();
    cout<<str<<endl;
}

void dfs(int u,int depth)
{
    if(u==0)return;
    max_depth=max(max_depth,depth);
    cnt[depth].push_back(u);
    dfs(l[u],depth+1);
    dfs(r[u],depth+1);
    // dfs在每一层的遍历顺序上是从左至右（或者说方向是一致的）


}


int main(){
    cin>>n;

    for(int i = 0;i<n;++i){
        cin>>in[i];
        in_mp[in[i]] = i;
    }
    for(int i = 0;i<n;++i) cin>>post[i];
    int root = build(0,n-1,0,n-1);
    // bfs(root);
    dfs(root,1);
    for(int i=1;i<=max_depth;i++)
    {
        auto& v=cnt[i];
        if(i%2) for(int i=v.size()-1;i>=0;i--)cout<<v[i]<<' ';
        else for(int i=0;i<v.size();i++)cout<<v[i]<<' ';
    }


    return 0;
}