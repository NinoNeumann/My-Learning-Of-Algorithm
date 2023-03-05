//
// Created by Nino Neumann on 2023/3/4.
//
// c++字符串匹配操作

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int N = 30;
int n;
vector<string> strs;
int usage[N];
int max_len;

void dfs(string head,int length){
    for(int i = 0;i<strs.size();++i){
        if(strs[i].find(head)!=0)continue;
        if(usage[i]>=2)continue;
        string s = strs[i];
        // 找到了一个合法的字
        // length+=(s.length()-head.length());

        usage[i]++;
        //匹配尾部
        for(int len = 1;len<s.length();++len){
            // cout<<s.substr(s.length()-len,len)<<endl;
            dfs(s.substr(s.length()-len,len),length+s.length()-head.length());
        }
        usage[i]--;
    }
    max_len = max(max_len,length);
}

int main(){
    cin>>n;
    for(int i = 0;i<n;++i) {
        string s;
        cin>>s;
        strs.push_back(s);
    }
    string head;
    cin>>head;
    dfs(head,head.length());
    cout<<max_len<<endl;


    return 0;
}