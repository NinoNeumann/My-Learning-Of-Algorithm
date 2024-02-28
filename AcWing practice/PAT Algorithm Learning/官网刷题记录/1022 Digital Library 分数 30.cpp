//
// Created by Nino Neumann on 2023/5/6.
// unoredered_map 题目

#include<iostream>
#include<unordered_map>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
const int N = 1e4+10;
#define CC(x) cout<<x<<endl


unordered_map<string,vector<string>> title_table,
        author_table,key_words_table,publisher_table,year_table;
int n;
int k;

int main(){
    cin>>n;
    getchar();
    for(int i = 0;i<n;++i){
        string id,title,author,publisher,year;
        getline(cin,id);
        getline(cin,title);
        getline(cin,author);
        string line;
        getline(cin,line);
        stringstream ssin(line);
        string word;
        while(ssin>>word){
            key_words_table[word].push_back(id);
        }
        getline(cin,publisher);
        getline(cin,year);
        title_table[title].push_back(id);
        author_table[author].push_back(id);
        publisher_table[publisher].push_back(id);
        year_table[year].push_back(id);
    }
    cin>>k;
    getchar();
    while(k--){
        string line;
        getline(cin,line);
        vector<string> res;
        string str = line.substr(3,line.length()-3);
        switch(line[0]){
            case '1': res = title_table[str];break;
            case '2': res = author_table[str];break;
            case '3': res = key_words_table[str];break;
            case '4': res = publisher_table[str];break;
            case '5': res = year_table[str];break;
        }
        sort(res.begin(),res.end());
        CC(line);
        if(res.size()) for(auto x:res) CC(x);
        else CC("Not Found");
    }

    return 0;
}
