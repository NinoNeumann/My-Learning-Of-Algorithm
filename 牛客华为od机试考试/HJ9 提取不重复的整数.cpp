//
// Created by Nino Neumann on 2024/2/22.
//
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char,bool> ht;

int main() {
    string str;
    cin>>str;
    for(int i = str.size()-1;i>=0;--i){
        if(!ht[str[i]]){
            ht[str[i]] = true;
            cout<<str[i];
        }
    }
}
// 64 位输出请用 printf("%lld")

