//
// Created by Nino Neumann on 2023/4/9.
//
#include<iostream>
using namespace std;

void dfs(){
    char x;
    scanf("%c",&x);
    if(x>='a' && x<='z'){
        dfs();
        printf("%c ",x);
        dfs();
    }
}
int main(){
    dfs();
    return 0;
}