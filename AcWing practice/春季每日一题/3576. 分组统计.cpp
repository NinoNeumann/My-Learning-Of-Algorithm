//
// Created by Nino Neumann on 2023/4/20.
//
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
// 小组数连续且不为空  需要保存一个数值的集合

const int N = 110;

// vector<int> set[N];




int main(){
    int t,n;
    cin>>t;
    while(t--){
        unordered_map<int,int> set[N];
        int number[N];
        int gs[N];
        cin>>n;
        int mx_group = 0;
        for(int i = 0;i<n;++i)cin>>number[i];
        for(int i = 0;i<n;++i) cin>>gs[i];
        for(int i = 0;i<n;++i){
            set[gs[i]][number[i]]++;
            mx_group = max(mx_group,gs[i]);
        }
        sort(number,number+n);
        int k = unique(number,number+n)-number;
        // 输出

        for(int g = 1;g<=mx_group;++g){
            cout<<g<<"={";
            for(int i = 0;i<k;++i){
                cout<<number[i]<<"="<<set[g][number[i]];
                if(i+1<k)cout<<",";
                else cout<<"}\n";
            }
        }

    }

    return 0;
}
