
// 使用排名表 按照成绩查询表查询名次
#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 2010;
map<int,vector<int>> stus;
vector<int> grades[4];
string r = "ACME";

bool cmp(int a,int b){
    return a>b;
}

int get_rank(vector<int> g,int ms){
    // 二分查找
    int l = 0,r = g.size()-1;
    while(l<r){
        int mid = (l + r + 1) >> 1;
        if(g[mid]<=ms) l = mid;
        else r = mid-1;
    }
    return g.size()-l;
}


int main(){
    int n,q;
    cin>>n>>q;
    while(n--){
        int c,d;
        cin>>d;
        vector<int> g(4,0);
        int m = 0;
        for(int i = 1;i<4;++i){
            cin>>c;
            grades[i].push_back(c);
            g[i] = c;
            m+=c;
        }
        grades[0].push_back(round(m/3.0));
        g[0] = round(m/3.0);
        stus[d] = g;
    }
    for(int i = 0;i<4;++i){
        sort(grades[i].begin(),grades[i].end());
    }

    while(q--){
        int d;
        cin>>d;
        if(stus.find(d)==stus.end()){
            cout<<"N/A\n";
        }else{
            int best = N;
            char record;
            for(int i = 0;i<4;++i){
                int rank = get_rank(grades[i],stus[d][i]);
                if(rank<best){
                    best = rank;
                    record = r[i];
                }
            }
            cout<<best<<" "<<record<<endl;
        }
    }

    return 0;
}
