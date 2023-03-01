//
// Created by Nino Neumann on 2023/3/1.
//
// 思路：输入的是 坐标+操作数
// 坐标是唯一的之后的询问
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> PII;


const int N = 3e5+10;
int a[N];
int s[N]; // 坐标之和 类似前缀和
vector<PII> add,query;
vector<int> alls;
int n,m;

int find(int x){
    // 通过二分查找查找x所在的下标位置
    int l = 0,r = alls.size()-1;
    while(l<r){
        int mid = l+r>>1;
        if(alls[mid]>=x) r = mid;
        else l = mid+1;
    }
    return r+1;
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<n;++i){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        add.push_back({t1,t2});
        alls.push_back(t1);
    }

    for(int i = 0;i<m;++i){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        query.push_back({t1,t2});
        alls.push_back(t1);
        alls.push_back(t2);
    }

    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    // 需要将出现的所有的坐标转换到一个a数组的下标 实现这个功能的介质是all数组
    for(auto ad:add){
        int x = find(ad.first);
        a[x]+=ad.second;
    }
    for(int i = 1;i<=alls.size();++i) s[i] = s[i-1] + a[i];

    for(auto q:query){
        int l = find(q.first);
        int r = find(q.second);
        printf("%d\n",s[r]-s[l-1]);

    }


    return 0;
}

