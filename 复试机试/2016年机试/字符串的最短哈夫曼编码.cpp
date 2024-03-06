//
// Created by Nino Neumann on 2024/3/6.
//

// acwing 相关题目 https://www.acwing.com/solution/content/3258/

// 哈夫曼树的构造
// 堆、

#include "iostream"
#include "queue"
#include "unordered_map"
using namespace std;

unordered_map<char,int> mp; // 记录字符出现次数
priority_queue<int,vector<int>,greater<int>> s_heap; // 小根堆
int main(){
    int res = 0;
    string s;
    cin>>s;
    for(int i = 0;i<s.size();++i){
        mp[s[i]]++;
    }
    for(auto x:mp){
        s_heap.push(x.second);
    }
    while(s_heap.size()>1){
        int k1 = s_heap.top(); s_heap.pop();
        int k2 = s_heap.top(); s_heap.pop();
        s_heap.push(k1+k2);
        res += k1 + k2;
    }
    cout<<res<<endl;
    return 0;
}
