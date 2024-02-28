//
// Created by Nino Neumann on 2024/2/22.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    char c;
    string str;
    int n = 0;
    while ((c = getchar()) != '\n') {
        n++;
        str+=c;
        if(n%8==0){
            cout<<str<<endl;
            str = "";
        }
    }
    if(n%8){
        cout<<str;
        while(n%8){
            cout<<0;
            n++;
        }
        cout<<endl;
    }
    return 0;
}
// 1、while ((c = getchar()) != '\n') 从缓存中逐个读取字符注意换行符。