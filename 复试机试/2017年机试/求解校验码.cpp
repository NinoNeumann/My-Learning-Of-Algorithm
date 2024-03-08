//
// Created by Nino Neumann on 2024/3/7.
//

#include "iostream"
#include "string"
using namespace std;
// 字符串处理



int main(){
    string ISBN;
    int S = 0;
    int k = 10;
    cin>>ISBN;
    // ISBN 是一个9位数的数字
    for (int i = 0; i < ISBN.size(); ++i)
        if(isdigit(ISBN[i]))
            S += (k--)*(ISBN[i]-'0');
    cout<<ISBN<<'-';
    S %= 11;
    if(S==0) cout<<'0'<<endl;
    else if(S==1) cout<<'X'<<endl;
    else cout<<11-S<<endl;
    return 0;
}
