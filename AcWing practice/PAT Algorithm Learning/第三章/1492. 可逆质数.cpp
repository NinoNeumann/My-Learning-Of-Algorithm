//
// Created by Nino Neumann on 2023/3/29.
//
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5+10;


bool is_prime(int a){
    if(a<2) return false;
    for(int i = 2;i*i<=a;++i){
        if(a%i==0)return false;
    }
    return true;
}

// 将一个十进制数转化为D进制数

string convert(int a,int d){
    string res = "";
    while(a){
        int k = a%d;
        a/=d;
        res  = res + (char)(k + '0');
    }
    return res;
}

int reconvert(string a,int d){
    int res = 0;
    // reverse(a.begin(),a.end());
    for(auto c:a){
        res = res*d+(c-'0');
    }
    return res;
}

int main(){
    int n,d;
    while(1){
        cin>>n;
        if(n<0) return 0;
        cin>>d;
        string cnvt = convert(n,d);
        int recvt = reconvert(cnvt,d);
        // cout<<"n: "<<n<<" d: "<<d<<" cvt: "<<cnvt<<" rcvt: "<<recvt<<endl;
        // cout<<n<<" "<<is_prime(n)<<endl;
        if(is_prime(recvt) && is_prime(n)){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    return 0;
}
