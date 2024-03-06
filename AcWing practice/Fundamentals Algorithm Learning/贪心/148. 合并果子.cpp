//
// Created by Nino Neumann on 2024/3/6.
//

#include "iostream"
#include "queue"
#include "unordered_map"
using namespace std;

const int N = 10000;

int num;
int n;

priority_queue<int,vector<int>,greater<int>> s_heap;
int main(){
    ios::sync_with_stdio(false);
    int res = 0;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>num;
        s_heap.push(num);
    }
    while(s_heap.size()>1){
        int k1 = s_heap.top(); s_heap.pop();
        int k2 = s_heap.top(); s_heap.pop();
        res += k1 + k2;
    }
    cout<< res <<endl;


    return 0;
}

