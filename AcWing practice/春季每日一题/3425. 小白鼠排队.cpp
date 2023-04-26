//
// Created by Nino Neumann on 2023/4/25.
//
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 110;

struct mouse{
    int w;
    char color[11];
    bool operator<(mouse &a) const {
        return w>a.w;
    }
};


mouse m[N];

int n;

int main(){
    cin>>n;

    for(int i = 0;i<n;++i){
        cin>>m[i].w>>m[i].color;
    }
    sort(m,m+n);
    for(int i = 0;i<n;++i){
        cout<<m[i].color<<endl;
    }

    return 0;
}