//
// Created by Nino Neumann on 2023/4/24.
//
#include<iostream>
#include<unordered_map>
using namespace std;


const int N = 5e4+10;

int inorder[N],preorder[N];
unordered_map<int,int> pos;
int n;

void search(int pl,int pr,int il,int ir){
    if(pl==pr && il==ir){
        cout<<inorder[ir]<<endl;
        return;
    }

    int root = preorder[pl];
    int k = pos[root];
    if(k>il) {
        search(pl+1,pl+k-il,il,k-1);
    }else{
        search(pl+k-il+1,pr,k+1,ir);
    }
    return ;
}

int main(){
    cin>>n;

    for(int i = 0;i<n;++i) cin>>preorder[i];
    for(int i = 0;i<n;++i){
        cin>>inorder[i];
        pos[inorder[i]] = i;
    }

    search(0,n-1,0,n-1);


    return 0;
}