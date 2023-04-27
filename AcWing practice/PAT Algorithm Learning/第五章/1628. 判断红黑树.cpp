//
// Created by Nino Neumann on 2023/4/27.
//
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<cmath>
using namespace std;


const int N = 40;
int in[N]; // 记录每条路径中的黑节点数量
int n,idx;
int pre[N];
bool ans;
unordered_map<int, int> pos;


bool cmp(int a,int b){
    return abs(a)<abs(b);
}


int build(int pl,int pr,int il,int ir,int &sum){
    int root = pre[pl];
    int k = pos[root];
    int left = 0,right = 0,ls = 0,rs = 0;
    if(k < il || k > ir){
        ans = false;
        return 0;
    }
    if(il<k) left = build(pl+1,pl+1+k-1-il,il,k-1,ls);
    if(k<ir) right = build(pl+1+k-1-il+1,pr,k+1,ir,rs);

    if (ls != rs) ans = false;
    sum = ls;
    if(root<0){
        if(left<0 || right<0){
            ans = false;
        }
    }else sum++;


    return root;
}


int main(){
    cin>>n;
    while(n--){
        ans = true;
        pos.clear();
        int k;
        cin>>k;
        for(int i = 0;i<k;++i){
            cin>>pre[i];
            in[i] = pre[i];
        }
        sort(in,in+k,cmp);
        for(int i = 0;i<k;++i) pos[in[i]] = i;
        int num = 0;
        int root = build(0,k-1,0,k-1,num);
        // cout<<ans<<endl;
        if(root<0 || !ans) cout<<"No\n";
        else cout<<"Yes\n";

    }

    return 0;
}

