//
// Created by Nino Neumann on 2023/4/27.
//
#include<iostream>
#include<vector>
using namespace std;

const int N = 1e3+10;

// 用两个全局变量表示四种可能状态。
int tree[N];
int n;
vector<int> path;
bool gt,lt;
int is_max_or_min;

void dfs(int root){
    // 问题在于简化版本的dfs
    path.push_back(tree[root]);
    int r = (root<<1) + 1;
    int l = root<<1;
    if((root<<1) > n){
        // 叶子节点
        cout<<path[0];
        for(int i = 1;i<path.size();++i){
            cout<<' '<<path[i];
            if(path[i-1]>path[i]) gt = true;
            else if(path[i-1]<path[i]) lt = true;
        }
        cout<<endl;
    }

    if(r<=n) dfs(r);
    if(l<=n) dfs(l);

    path.pop_back();
    return;

}

int main(){
    cin>>n;
    for(int i = 1;i<=n;++i) cin>>tree[i];
    // path.push_back(tree[1]);
    dfs(1);

    // 从所有的序列中判断是否都是 非递减（小根） 或者 非递增（大根）
    if(gt && lt) cout<<"Not Heap\n";
    else if(lt) cout<<"Min Heap\n";
    else if(gt) cout<<"Max Heap\n";
    return 0;
}