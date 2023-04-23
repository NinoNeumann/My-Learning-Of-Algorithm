//
// Created by Nino Neumann on 2023/4/23.
//
#include<iostream>
#include<cstring>
using namespace std;

const int N = 40;
int n;

void preorder(int root){
    int w;
    string str;
    cin>>str;
    if(str[1]=='u'){
        // push 操作
        cin>>w;
        preorder(root*2);
        preorder(root*2+1);
        cout<<w;
        if(root!=1)cout<<" ";  //结尾不能有多余的空格。
    }
}


int main(){
    cin>>n;
    preorder(1);
    return 0;
}