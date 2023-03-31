
//
// Created by Nino Neumann on 2023/3/31.
//
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

const int N = 1e4+10;

map<string,vector<string>> mp[5];



int n,q;
int main(){
    cin>>n;
    while(n--){
        string line;
        string id;
        cin>>id;
        getchar();
        for(int i = 0;i<5;++i){
            getline(cin,line);
            stringstream ssin(line);
            if(i==2){
                string word;
                while(ssin>>word){
                    mp[i][word].push_back(id);
                }
            }else
                mp[i][line].push_back(id);
            // cout<<i<<" : "<<line<<endl;
        }
    }
    cin>>q;
    getchar();
    while(q--){
        string line;
        getline(cin,line);
        string query_content = line.substr(3,line.size()-3);
        int query_idx = line[0]-'0'-1;
        // cout<<"idx: "<<query_idx<<" content:"<<query_content<<endl;
        cout<<line<<endl;

        if(mp[query_idx].find(query_content)==mp[query_idx].end()){
            cout<<"Not Found\n";
        }else{
            sort(mp[query_idx][query_content].begin(),mp[query_idx][query_content].end());
            for(auto c:mp[query_idx][query_content])cout<<c<<endl;
        }
    }


    return 0;
}

