//
// Created by Nino Neumann on 2023/4/7.
//
#include<iostream>
#include<vector>
#include<map>


using namespace std;


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,pair<double,bool>>>> hash_table; // 最里面的pair,second是个tag:0 表示从前往后做除法 1 表示从后往前做乘法
        for(int i = 0;i<equations.size();++i){
            string pre = equations[i][0],post = equations[i][1];
            hash_table[pre].push_back({post,{values[i],0}}) ;
            hash_table[post].push_back({pre,{values[i],1}}) ;
        }

    }
};