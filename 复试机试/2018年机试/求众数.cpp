//
// Created by Nino Neumann on 2024/3/7.
//

/*
 * 众数就是一个序列中出现次数最多的数字。 如果不唯一，则输出小的那个值。
 * */
#include "iostream"
#include "map"
using namespace std;
map<int,int> mp;
int main(){
    ios::sync_with_stdio(false);
    int n;
    int mx_cnt = 0;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin>>t;
        if(mp.find(t)==mp.end()) mp[t] = 1;
        else mp[t]++;
        mx_cnt = max(mx_cnt,mp[t]);
    }
    for(auto x:mp){
        if(mx_cnt==x.second){
            cout<<x.first<<endl;
            break;
        }
    }


    return 0;
}
