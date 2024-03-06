//
// Created by Nino Neumann on 2024/3/6.
//


/*
 * 输入一棵二叉树，输出树的前、中、后序遍历结果。
输入一个整数N（N<= 10000)，表示树中有N个结点（编号0~N-1）。
接下来N行，依次为结点0~结点N-1的左右孩子情况。
每行3个整数，F,L,R。L,R为F的左右孩子。L,R如果为-1表示该位置上没有孩子。
分三行分别输出树的前中后序遍历。
同一行中的数字，用一个空格间隔。
 *
 * */

#include "iostream"
#include "vector"
#include "cstring"
using namespace std;

const int N = 80001;

int ltree[N],rtree[N],idx;
bool not_root[N];
int n;
vector<int> preorder,inorder,postorder;

void traverse(int root){
    if(root==-1) return ;
    preorder.push_back(root);
    traverse(ltree[root]);
    inorder.push_back(root);
    traverse(rtree[root]);
    postorder.push_back(root);
    return;
}

int main(){
    ios::sync_with_stdio(false);
//    memset(ltree,-1, sizeof ltree);
//    memset(rtree,-1, sizeof rtree);
    int root;
    cin>>n;
    for(int i = 0;i<n;++i){
        int f,l,r;
        cin>>f>>l>>r;
        ltree[f] = l;
        rtree[f] = r;
        not_root[l] = true;
        not_root[r] = true;
    }
    for(int i = 0;i<n;++i){
        if(!not_root[i]){
            root = i;
            break;
        }
    }
    traverse(root);
    for(auto x:preorder) cout<<x<<' ';
    cout<<endl;
    for(auto x:inorder) cout<<x<<' ';
    cout<<endl;
    for(auto x:postorder) cout<<x<<' ';
    return 0;
}