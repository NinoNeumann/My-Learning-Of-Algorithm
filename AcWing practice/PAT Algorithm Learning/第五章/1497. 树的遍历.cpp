//
// Created by Nino Neumann on 2023/4/18.
//
#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

const int N = 40;

int postordered[N],inordered[N];

unordered_map<int, int> l,r,ipost;

int n;

int build(int pl,int pr,int il,int ir){
    int root  = postordered[pr];
    int k = ipost[root];
    if(il<k){
        l[root] = build(pl,pl+k-1-il,il,k-1);
    }
    if(ir>k){
        r[root] = build(pl+k-1-il+1,pr-1,k+1,ir);
    }
    return root;
}

void bfs(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        cout<<t<<" ";
        if(l.count(t)) q.push(l[t]);
        if(r.count(t)) q.push(r[t]);
    }
}

int main(){
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>postordered[i];
    }

    for(int i = 0;i<n;i++){
        cin>>inordered[i];
        ipost[inordered[i]] = i;
    }

    int root = build(0,n-1,0,n-1);
    bfs(root);



    return 0;
}