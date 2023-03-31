//
// Created by Nino Neumann on 2023/3/31.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct student{
    string id,name;
    int score;
};

int c;

bool operator<(student &a,student &b) {
    if(c==1)
        return a.id<b.id;
    if(c==2)
        return a.name==b.name ? a.id<b.id : a.name>=b.name;
    if(c==3)
        return a.score==b.score ? a.id<b.id : a.score>=b.score;
}


int main(){
    int n;
    cin>>n>>c;
    priority_queue<student,vector<student>, less<student>> heap;
    while(n--){
        string id,name;
        int grade;
        cin>>id>>name>>grade;
//        students.push_back({id,name,grade});
        heap.push({id,name,grade})
    }

    while(!heap.empty()){
        auto s = heap.top();
        heap.pop();
        cout<<s.id<<" "<<s.name<<" "<<s.score<<endl;
    }



    return 0;
}