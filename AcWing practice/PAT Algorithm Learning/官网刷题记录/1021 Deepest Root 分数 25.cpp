////
//// Created by Nino Neumann on 2023/5/6.
////
//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//
//// 对于如何判断当前图是否是连通的可以使用并查集
//const int N = 1e4+10;
//vector<int> heads[N];
//bool st[N];
//int p[N];
//int n;
//
//int find(int a){
//    if(p[a]!=a) p[a] = find(p[a]);
//    return p[a];
//}
//void init(){
//    for(int i = 0;i<=n;++i){
//        p[i] = i;
//    }
//}
//// 值得思考的地方在这里 如何计算一个连通图中的最深根
//int dfs(int root){
//    // 计算当前节点的最大深度
//    // 因为有可能会有环所以使用辅助数组st 来标记此次遍历中已经被遍历过的点
//    int current_depth;
//    st[root] = true;
//    int max_son_depth = 0; // 记录孩子节点中最深的深度
//    for(auto x:heads[root]){
//        if(!st[x]){
//            max_son_depth = max(max_son_depth,dfs(x));
//        }
//    }
//    current_depth = max_son_depth+1;
//    return current_depth;
//
//}
//
//int main(){
//    cin>>n;
//    int cnt = n;
//    init();
//    for(int i = 1;i<=n;++i){
//        int a,b;
//        cin>>a>>b;
//        heads[a].push_back(b);
//        heads[b].push_back(a);
//        int fa = find(a), fb = find(b);
//        if(fa!=fb){
//            cnt--;
//            p[fa] = fb;
//        }
//    }
//    if(cnt==1){
//        vector<int> res_set;
//        int mx_depth = 0;
//        for(int i = 1;i<=n;++i){
//            memset(st,0,sizeof st);
//            int depth = dfs(i);
//            if(depth>mx_depth){
//                res_set.clear();
//                mx_depth = depth;
//                res_set.push_back(i);
//            }else if(depth==mx_depth){
//                res_set.push_back(i);
//            }
//        }
//        for(auto x:res_set)cout<<x<<endl;
//    }else{
//        cout<<"Error: "<<cnt<<" components\n";
//    }
//
//    return 0;
//}
//
//
//
//
// 这道题acwing上给出了更加严格的测试用例
//
// Created by Nino Neumann on 2023/5/6.
//
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

// 对于如何判断当前图是否是连通的可以使用并查集
const int N = 1e4+10;
const int M = N*2;
// vector<int> heads[N];
int h[N],e[M],ne[M],idx;
int p[N];
int n;

void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}


int find(int a){
    if(p[a]!=a) p[a] = find(p[a]);
    return p[a];
}
void init(){
    for(int i = 0;i<=n;++i){
        p[i] = i;
    }
}
// 值得思考的地方在这里 如何计算一个连通图中的最深根
int dfs(int root,int fa){
    // 计算当前节点的最大深度
    // 因为有可能会有环所以使用辅助数组st 来标记此次遍历中已经被遍历过的点
    int current_depth;
    int max_son_depth = 0; // 记录孩子节点中最深的深度

    for(int i = h[root];~i;i = ne[i]){
        int x = e[i];
        if(x==fa) continue;
        max_son_depth = max(max_son_depth,dfs(x,root));
    }
    current_depth = max_son_depth+1;
    return current_depth;

}

int main(){
    cin>>n;
    int cnt = n;
    init();
    memset(h,-1,sizeof h);
    for(int i = 1;i<=n;++i){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
        int fa = find(a), fb = find(b);
        if(fa!=fb){
            cnt--;
            p[fa] = fb;
        }
    }
    if(cnt==1){
        vector<int> res_set;
        int mx_depth = 0;
        for(int i = 1;i<=n;++i){
            int depth = dfs(i,-1);
            if(depth>mx_depth){
                res_set.clear();
                mx_depth = depth;
                res_set.push_back(i);
            }else if(depth==mx_depth){
                res_set.push_back(i);
            }
        }
        for(auto x:res_set)cout<<x<<endl;
    }else{
        cout<<"Error: "<<cnt<<" components\n";
    }

    return 0;
}


// 参考以下上面的构建简易邻接表的方法和 dfs的方法