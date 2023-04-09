//
// Created by Nino Neumann on 2023/4/1.
//
#include<iostream>
//#include<unordered_map>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

const int K = 6;


struct info{
    string id;
    int t_score;
    int prior;
    bool operator<(const info &a) const{
        return t_score==a.t_score? (prior==a.prior?id<a.id:prior>a.prior):t_score>a.t_score;
    }
};


unordered_map<string,int> hash_map[K];

int full_score[K];
vector<info> total_scores;
unordered_map<string,int> user_list;



int n,k,m;


int get_rank(int s,vector<int> t){
    int l = 0,r = t.size()-1;
    while(l<r){
        int mid = (l+r+1)>>1;
        if(t[mid]<=s) l = mid;
        else r = mid-1;
    }
    return t.size()-l;
}


int main(){

    scanf("%d%d%d",&n,&k,&m);
    for(int i = 1;i<=k;++i)
        scanf("%d",&full_score[i]);

    while(m--){
        char c[10];
        int q_id,score;
        scanf("%s%d%d",c,&q_id,&score);

        string id(c);
        user_list[id] = 1;
        // 如果是第一次遇见这个题目并且编译失败则是-1 下一次就是max
        if(hash_map[q_id].find(id)==hash_map[q_id].end() && score==-1)
            hash_map[q_id][id] = score;
        else
        hash_map[q_id][id] = max(hash_map[q_id][id],score);
    }
    //形成总分排名表
    for(auto u:user_list){
        int total = 0;
        string user = u.first;
        int full_score_num = 0;
        int is_legal = k;
        // 计算k道题的总分
        for(int i = 1;i<=k;++i){
            if(hash_map[i].find(user)!=hash_map[i].end()){
                if( hash_map[i][user]!=-1)
                    total += hash_map[i][user];
                else
                    is_legal--;
                if(hash_map[i][user]==full_score[i]) full_score_num++;
            }else
                is_legal--;

        }
        // 对于任何未提交或者编译未通过的用户 都不予考虑。
        if(is_legal){
            total_scores.push_back({user,total,full_score_num});
        }

    }
    sort(total_scores.begin(),total_scores.end());
    int rank = 1;
    for(int i = 0;i<total_scores.size();++i){
        string user = total_scores[i].id;
        int score = total_scores[i].t_score;
        if(i!=0 && total_scores[i-1].t_score!=score){
            rank = i+1;
        }
        printf("%d %s %d ",rank,user.c_str(),score);
        for(int j = 1;j<=k;++j){
            if(hash_map[j].find(user)!=hash_map[j].end()){
                if(hash_map[j][user]!=-1)
                    printf("%d ",hash_map[j][user]);
                else
                    printf("0 ");
            }
            else
                printf("- ");
        }
        printf("\n");
    }

    return 0;
}