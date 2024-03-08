//
// Created by Nino Neumann on 2024/3/7.
//

/*
 * 输入两个集合，分别求其交集和并集中元素的个数，每个集合中可能存在
 * 相同的元素，而最终的交集和并集中应该不存在。
 * */

#include "iostream"
#include "unordered_set"
using namespace std;

unordered_set<int> a,b,a_and_b,a_or_b;
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        int t;
        cin>>t;
        a.insert(t);
        a_or_b.insert(t);
    }
    for (int i = 0; i < m; ++i) {
        int t;
        cin>>t;
        if(a.find(t)!=a.end() && a_and_b.find(t)==a_and_b.end())
            a_and_b.insert(t);
        if(a.find(t)==a.end() && a_or_b.find(t)==a_or_b.end())
            a_or_b.insert(t);
    }
    cout<<a_and_b.size()<<' '<<a_or_b.size();


    return 0;
}
