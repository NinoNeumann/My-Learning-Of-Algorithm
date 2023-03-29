//
// Created by Nino Neumann on 2023/3/29.
//
#include<iostream>
using namespace std;
const int ridx = 13;

char put(int c){
    if(c<=9)return c+'0';
    else return c-10+'A';
}

string convert(int a){
    string res = "";
    while(a){
        res = put(a%ridx)+res;
        a/=ridx;
    }
    while(res.length()<2) res = '0'+ res;
    return res;
}


int main(){
    int r,g,b;
    cin>>r>>g>>b;
    string res = "#";
    res = res+ convert(r)+ convert(g)+ convert(b);
    cout<<res<<endl;

    return 0;
}
