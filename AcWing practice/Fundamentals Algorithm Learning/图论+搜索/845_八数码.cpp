//
// Created by Nino Neumann on 2023/3/2.
//

// BFS中重要的几个要素
// 1 queue中应该装入什么状态
// 2 走迷宫中的 每一个状态对应的步数该如何表示 索引 存储
// 用的不顺的函数 string.find(char) 返回find的char在string中的位置
//             unordered_map.find() 查找成功和不成功返回什么
#include<iostream>
#include<queue>
#include<unordered_map>
#include<cstring>
using namespace std;


const int N = 3;
string str;
int dis_x[] = {-1,0,1,0};
int dis_y[] = {0,-1,0,1};

int bfs(){

    int res = 0;
    unordered_map<string,int> state;
    queue<string> q;
    q.push(str);
    state.insert({str,0});
    while(!q.empty()){
        auto t = q.front();
        q.pop();
//        int y = t.find('x')%3,x = t.find('x')/3; // t 对应的 x 和 y下标的映射 计算
        for(int i = 0;i<4;++i){
            int x = t.find('x')/3+dis_x[i];
            int y = t.find('x')%3 +dis_y[i];
            if(y<0 || x<0 || y>=3 || x>=3) continue;
            int pos = y+x*3;// 从x y到string一维下标的映射
            int step = state[t];
            string s = t;
            swap(s[s.find('x')],s[pos]);
            q.push(s);
            state.insert({s,step+1});
        }
    }
    return (state.find("12345678x")==state.end()?-1:state["12345678x"]);

}



int main(){
    for(int i = 0;i<9;++i){
        char t;
        cin>>t;
        str = str+t;
    }
    int y = str.find('x')%3,x = str.find('x')/3;
    cout<<x<<" "<<y<<endl;
    cout<<bfs()<<endl;
    return 0;
}
