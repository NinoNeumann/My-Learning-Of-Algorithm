//
// Created by Nino Neumann on 2023/4/4.
//
#include<iostream>
using namespace std;


const int N = 10;

int num[N];
int res[N];
bool is_select[N];
int n;

void print_result(){
    for(int i = 1;i<=n;++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}



void dfs(int step){
    // step 表示当前到哪一个位置了。
    if(step == n+1) {
        //表示已经到达最后一步了 可以输出了
        print_result();
        return;
    }
    // 在所有没有被添加进去的数字中选择一个填入
    for(int i = 1;i<=n;++i){
        if(!is_select[i]){
            is_select[i] = true;
            res[step] = i;
            dfs(step+1);
            is_select[i] = false;
        }
    }
}


int main(){
    cin>>n;
    dfs(1);
    return 0;
}