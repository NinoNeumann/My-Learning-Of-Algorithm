//
// Created by Nino Neumann on 2024/3/6.
//

/*
 *给出优先队列的实现，实现 4 个操作
ADD N P：往队列里加入id为N的优先级为P的任务
NEXT:输出下一个最高优先级的任务的id，如果优先级相同输出id小的任务
     若队列中没有任务输出-1
REMOVE N：移除id为N的任务
COUNT：输出队列中的任务数量
 * */
#include "iostream"
#include "set"
using namespace std;
struct node{
    int P,ID;
    bool operator<(const node &a){
        return P==a.P?ID<a.ID:P>a.P;
    }
};
set<node> heap;
void ADD(int P,int ID){
    heap.insert({P,ID});
}

int NEXT(){
    if(heap.empty()) return -1;
    return *heap.begin()->ID;
}

void REMOVE(int ID){
    for(auto x:heap){
        if(x.ID==ID) heap.erase(x);
    }
}
int COUNT(){
    return heap.size();
}
int main(){


    return 0;
}