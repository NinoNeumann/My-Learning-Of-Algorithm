//
// Created by Nino Neumann on 2023/4/15.
//
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string str;
    while(getline(cin,str)){
        int res = 0;
        for(int i = str.length()-1,k = 2;i>=0;--i,k<<=1)
            res += (str[i]-'0')*(k-1);
        cout<<res<<endl;
    }
}