//
// Created by Nino Neumann on 2024/2/22.
//
#include <iostream>
using namespace std;

int main() {
    string str;
    cin>>str;
    for(int i = str.size()-1;i>=0;--i) cout<<str[i];
    cout<<endl;
}
// 64 位输出请用 printf("%lld")