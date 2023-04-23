//
// Created by Nino Neumann on 2023/4/23.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> div_2(vector<int> &a,int &r){
    vector<int> c;
    r = 0;
    for(int i = a.size()-1;i>-1;--i){
        r = r*10+a[i];
        c.push_back(r>>1);
        r%=2;
    }
    reverse(c.begin(),c.end());
    while(c.size()>1 && c.back()==0) c.pop_back();
    return c;
}

vector<int> add(vector<int> a,vector<int> b){
    if(a.size()<b.size()) return add(b,a);

    vector<int> c;
    int t = 0;
    for(int i = 0;i<a.size();++i){
        t += a[i];
        if(i<b.size()) t+=b[i];
        c.push_back(t%10);
        t/=10;
    }

    if(t) c.push_back(t);
    return c;
}

bool cmp(vector<int> a){
    if(a.size()>1) return true;
    else return a[0];
}

vector<int> dec_to_bin(vector<int> &a){
    vector<int> b;
    while(cmp(a)){
        int r;
        a = div_2(a,r);
        b.push_back(r);
    }
    return b;
}

vector<int> bin_to_dec(vector<int> &b){  //二进制转十进制的算法很香。 秦九韶算法
    vector<int> d;
    d.push_back(0);
    for(int i = 0;i<b.size();++i){
        d = add(add(d,d),{b[i]});
    }
    return d;
}



int main(){
    string a_s;
    vector<int> a,b,d;
    cin>>a_s;

    for(int i = a_s.length()-1;i>-1;--i) a.push_back(a_s[i]-'0');
    b = dec_to_bin(a);

    d = bin_to_dec(b);

    for(int i = d.size() - 1; i >= 0; i --) cout << d[i];

    cout << endl;


    return 0;
}