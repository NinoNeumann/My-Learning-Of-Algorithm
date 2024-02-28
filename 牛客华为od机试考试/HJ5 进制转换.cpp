//
// Created by Nino Neumann on 2024/2/22.
//
#include <cctype>
#include <iostream>
using namespace std;

int main() {
    string str;
    int res = 0;
    cin>>str;
    int len = str.size();
    for(int i = str.size()-1;i>1;i--){
        int k = isalpha(str[i])?str[i]-'A'+10:str[i]-'0';
        int t = (str.size()-1-i)<<2;
        res+=(k<<t);
    }
    cout<<res<<endl;
}
/*
 *
 *  更简单的做法
int main() {
    int res;
    cin>>hex>>res;
    cout<<res<<endl;
}
 *
 * */
// 64 位输出请用 printf("%lld")
// 问题：i-str.size() 会出现溢出？


