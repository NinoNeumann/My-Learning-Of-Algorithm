//
// Created by Nino Neumann on 2023/4/1.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

struct node{
    string addr;
    int key;
    string addr_next;
    bool operator<(const node &a) const{
        return key<a.key;
    }
};

map<string,node> hash_table;
vector<node> nodes;

// 输入 删除 排序 输出

int main(){
    string ad;
    ad.resize(5);
    int n;
    scanf("%d%s",&n,&ad[0]);
    cout<<n<<endl;
    while(n--){
        string s;
        string o;
        s.resize(5);
        o.resize(5);
        int key;
        scanf("%s%d%s",&s[0],&key,&o[0]);
        hash_table[s] = {s,key,o};
//        nodes.push_back({s,key,o});
    }
//    if(nodes)
    string current_addr = ad;

    while(current_addr!="-1"){
        auto top_node = hash_table[current_addr];
        nodes.push_back(top_node);
        current_addr = top_node.addr_next;
    }
    sort(nodes.begin(),nodes.end());
//    cout<<nodes.size()<<endl;
    printf("%d %s",nodes.size(),nodes[0].addr.c_str());
    for(auto n:nodes){
        printf("%s %d %s",n.addr.c_str(),n.key,n.addr_next.c_str());
    }



    return 0;
}