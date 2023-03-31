//
// Created by Nino Neumann on 2023/3/31.
//
//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//#include<queue>
//using namespace std;
//
//struct info{
//    string id;
//    int grade;
//    int final_rank,location_number,local_rank;
//    bool operator<(const info &a) const{
//        if(final_rank==a.final_rank) return id<a.id;
//        return final_rank>a.final_rank;
//    }
//};
//
//
//vector<int> total_grade_list;
//vector<info> total_students_list;
////map<string,info> mp;
//
//
//int get_rank(int grade,vector<int> gl){
//    for(int i = 0;i<gl.size();++i)
//        if(gl[i]==grade)return i;
//    return -1;
//}
//
//bool cmp(int &a,int &b){
//    return a>b;
//}
//int main(){
//    int n;
//    cin>>n;
//    for(int i = 1;i<=n;++i){
//        int k;
//        cin>>k;
//        vector<pair<string,int>> local_info;
//        vector<int> local_grade_list;
//        while(k--){
//            string id;
//            int grade;
//            cin>>id>>grade;
//            local_grade_list.push_back(grade);
//            local_info.push_back({id,grade});
//            total_grade_list.push_back(grade);
//        }
//
//        sort(local_grade_list.begin(),local_grade_list.end(),cmp);
//
//        for(auto p:local_info){
//            string id = p.first;
//            int g = p.second;
//            int rank = get_rank(g,local_grade_list);
//            total_students_list.push_back({id,g,-1,i,rank});
//        }
//    }
//
//    sort(total_grade_list.begin(),total_grade_list.end(),cmp);
//    for(int i = 0;i<total_students_list.size();++i){
//        info *p = &total_students_list[i];
//        int g = p->grade;
//        p->final_rank = get_rank(g,total_grade_list);
//    }
//    sort(total_students_list.begin(),total_students_list.end());
//    for(auto stu:total_students_list){
//        cout<<stu.id<<" "<<stu.final_rank<<" "<<stu.location_number<<" "<<stu.local_rank<<endl;
//    }
//    return 0;
//}

#include<iostream>
#include<vector>
using namespace std;

struct student{
    string id;
    int score;
    int final_rank;
    int location_number;
    int local_rank;
};

bool cmp1(student &a,student &b){
    return a.score>b.score;
}
bool cmp2(student &a,student &b){
    return a.score==b.score?a.final_rank<b.final_rank:a.id<b.id;
}

vector<student> students;


int main(){
    int n;
    int c = 0;
    for(int i = 1;i<=n;++i){
        int k;
        cin>>k;
        for(int j = 0;j<k;++j){
            string id;
            int grade;
            students.push_back({id,grade,-1,i,-1});
            c++;
        }
        sort(students.begin()+c-k, students.begin()+c, cmp1);
        int rank = 1;
        for(int j = c-k;j<c;++j){
            if(j==c-k){
                students[j].local_rank = rank;
                continue;
            }
            if(students[j-1].score!=students[j].score){
                students[j].local_rank = ++rank;
            }
        }
    }
    sort(students.begin(),students.end(), cmp2);
    int rank = 1;
    for(int i = 0;i<students.size();++i){
        if(i==0){
            students[i].final_rank = rank;
            continue;
        }
        if(students[i-1].score!=students[i].score){
            students[i].final_rank = ++rank;
        }
    }
    cout<<students.size()<<endl;
    for(auto stu:students){
        cout<<stu.id<<" "<<stu.final_rank<<" "stu.location_number<<" "<<stu.local_rank<<endl;
    }


    return 0;
}
