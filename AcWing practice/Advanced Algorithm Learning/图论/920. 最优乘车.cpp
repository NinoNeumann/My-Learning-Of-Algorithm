//
// Created by Nino Neumann on 2023/4/11.
//
#include<iostream>
#include<vector>
#include<cstring>
#include<sstream>
#include<queue>
using namespace std;

const int N = 550;
const int INF = 0x3f3f3f3f;

struct edge{
    int o,tag;
};
struct head{
    vector<edge> e;
};

head heads[N];
int dist[N];
bool st[N];

int n,m;

int spfa(){
    memset(dist,0x3f,sizeof dist);
    dist[1] = 0;
    queue<pair<int,int>> q;
    q.push({1,-1});
    st[1] = true;
    while(!q.empty()){
        auto top = q.front();
        int x = top.first;
        int current_tag = top.second;
        q.pop();
        st[x] = false;
        for(auto edges:heads[x].e){
            int y = edges.o,tag = edges.tag;
            int change_dist;
            if(tag!=current_tag && current_tag!=-1) change_dist = dist[x]+1;
            else change_dist = dist[x];
            if(change_dist<=dist[y]){
                dist[y] = change_dist;
                if(!st[y]){
                    q.push({y,tag});
                    st[y] = true;
                }
            }
        }
    }
    if(dist[n]==INF) return -1;
    return dist[n];
}


int main(){
    cin>>m>>n;
    getchar();
    for(int i = 1;i<=n;++i){
        string str;
        int pre,post;
        getline(cin,str);
        stringstream ssin(str);
        ssin>>pre;
        while(ssin>>post){
            heads[pre].e.push_back({post,i});

            // cout<<"edges:"<<pre<<","<<post<<" idx:"<<i<<" ";
            pre = post;

        }
        // cout<<endl;
    }
    int res = spfa();
    if(res==-1) cout<<"NO\n";
    else cout<<res<<endl;

    // cout<<spfa()<<endl;
    // cout<<"48:"<<dist[48]<<endl;
    // cout<<"22:"<<dist[47]<<endl;


    return 0;
}