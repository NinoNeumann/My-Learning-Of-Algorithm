//
// Created by Nino Neumann on 2024/3/1.
//
#include<iostream>
#include<string>
using namespace std;


const int N = 10000;

// 大致思想是 从中间往两边扩，按照回文关系 扩的最大的便是最长回文子串
pair<int,int> expand(const string &str, int s,int e){
    while(s>=0 && e<str.size() && str[s]==str[e])
        s--,e++;
    return {s+1,e-1};
}

int main(){
    string str;
    int start = 0, end = 0;
    getline(cin,str);
    for(int i = 0;i<str.size();++i){
        auto [left,right] = expand(str,i,i);
        auto [left1,right1] = expand(str,i,i+1);
        if(right-left > end-start)
            start = left, end = right;
        if(right1-left1 > end-start)
            start = left1, end = right1;
    }
    cout<<str.substr(start,end-start+1).size();
    return 0;
}