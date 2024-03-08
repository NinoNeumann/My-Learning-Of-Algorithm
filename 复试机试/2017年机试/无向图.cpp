//
// Created by Nino Neumann on 2024/3/7.
//

// 最小生成树！！！
#include "iostream"
#include "cstring"
#include "unordered_set"
using namespace std;
const int N = 500;
const int INF = 0x3f3f3f3f;

int g[N][N];
set<int> mp;
int dist[N];
bool st[N];

int n,m,k;

int prime(){
    int res = 0;
    memset(dist,0x3f,sizeof dist);
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j)
            if(!st[j] && (t==-1 || dist[j]<dist[t]))
                t = j;
        if(i && dist[t]==INF) return INF;
        if(i) res+=dist[t];
        st[t] = true;
        for(int j = 1;j<=n;++j)
            dist[j] = min(dist[j],g[t][j]);
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);

    cin>>n>>m>>k;
    for (int i = 0; i < k; ++i) {
        int t;
        cin>>t;
        mp.insert(t);
    }
    for (int i = 1; i <= m; ++i) {
        if(mp.find(i)!=mp.end()){
            int u,v,d;
            cin>>u>>v>>d;
            g[u][v] = g[v][u] = min(g[u][v],d);
        }
    }

    int res = prime();

    if(res==INF) cout<<'-1'<<endl;
    else cout<<res<<endl;

    return 0;
}
