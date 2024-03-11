//
// Created by Nino Neumann on 2024/3/10.
//
#include "iostream"
#include "algorithm"
using namespace std;
const int N = 1e5+10;

struct node{
    int a,b;
    bool operator<(const node &q){
        if(a==q.a) return b<q.b;
        return a<q.a;
    }
} interval[N];
int s,t,n;

bool if_include(const node &a,int s){
    // 判断区间是否包含点
    return a.a<=s && a.b>=s;
}


int main(){
    ios::sync_with_stdio(false);
    cin>>s>>t;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>interval[i].a>>interval[i].b;
    }
    sort(interval,interval+n);
    for (int i = 0; i < n; ++i) {
        // 如果当前区间包含 s 但是下一个区间不包含s
        if()
    }



    return 0;
}
