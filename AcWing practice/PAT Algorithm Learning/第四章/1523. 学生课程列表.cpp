//
// Created by Nino Neumann on 2023/4/1.
//
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

map<string,vector<int>> students;


int n,k;

int main(){
    scanf("%d%d",&n,&k);
    while(k--){
        int c_id,member_num;
        scanf("%d%d",&c_id,&member_num);
        while(member_num--){
            string s;
            s.resize(4);
            scanf("%s",&s[0]);
            students[s].push_back(c_id);
        }
    }
    //query
    while(n--){
        string s;
        s.resize(4);
        scanf("%s",&s[0]);
        printf("%s ",s.c_str());
        if(students.find(s)!=students.end()){
            sort(students[s].begin(),students[s].end());
            printf("%d ",students[s].size());
            
            for(auto c:students[s])
                printf("%d ",c);
        }else{
            printf("0");
        }
        printf("\n");
    }

    return 0;
}
