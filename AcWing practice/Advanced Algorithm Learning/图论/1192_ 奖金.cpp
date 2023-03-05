//
// Created by Nino Neumann on 2023/3/5.
//
// 如何定义薪资的等级
// 做法存在错误 似乎是没找到最小值
//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//
//const int N = 1e4+10;
//
//
//
//struct h{
//    vector<int>e;
//};
//
//h g[N];
//int d[N]; // 定义出度
//int level[N]; // 定义员工的薪资等级
//vector<int> seq;
//int mx;
//int n,m;
//
//void bfs(){
//    queue<int> q;
//
//    for(int i = 1;i<=n;++i){
//        if(!d[i]) {
//            q.push(i);
//            level[i] = 1;
//            mx = 1;
//        }
//    }
//    while(!q.empty()){
//        int t = q.front();
//        q.pop();
//        seq.push_back(t);
//        for(auto x:g[t].e){
//            d[x]--;
//            if(!d[x]){
//                q.push(x);
//                level[x] = level[t]+1;
//                mx = max(mx,level[x]);
//            }
//        }
//    }
//}
//
//
//int main(){
//    int res = 0;
//    cin>>n>>m;
//    for(int i = 0;i<m;++i){
//        int t1,t2;
//        scanf("%d%d",&t1,&t2);
//        g[t1].e.push_back(t2);
//        d[t2]++;
//    }
//    bfs();
//    if(seq.size()!=n)cout<<"Poor Xed";
//    else{
//        for(int i = 1;i<=n;++i){
//            res += (mx-level[i]+100);
//        }
//        cout<<res;
//    }
//    return 0;
//}

//
// Created by Nino Neumann on 2023/3/5.
//
// 如何定义薪资的等级
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N = 1e4+10;



struct h{
    vector<int>e;
};

h g[N];
int d[N]; // 定义出度
int salary[N]; // 定义员工的薪资等级
vector<int> seq;
int mx;
int n,m;

void bfs(){
    queue<int> q;

    for(int i = 1;i<=n;++i){
        if(!d[i]) {
            q.push(i);
            salary[i] = 100;

        }
    }
    while(!q.empty()){
        int t = q.front();
        q.pop();
        seq.push_back(t);
        for(auto x:g[t].e){
            d[x]--;
            if(!d[x]){
                q.push(x);
                salary[x] = salary[t]+1;
//                mx = max(mx,level[x]);
            }
        }
    }
}


int main(){
    int res = 0;
    cin>>n>>m;
    for(int i = 0;i<m;++i){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        g[t2].e.push_back(t1);
        d[t1]++;
    }
    bfs();
    if(seq.size()!=n)cout<<"Poor Xed";
    else{
        for(int i = 1;i<=n;++i){
            res += salary[i];
        }
        cout<<res;
    }
    return 0;
}

