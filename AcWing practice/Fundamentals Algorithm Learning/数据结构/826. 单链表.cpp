//
// Created by Nino Neumann on 2023/4/2.
//
#include<iostream>
using namespace std;


const int N = 1e5+10;

int e[N],ne[N],head,idx;  //head 记录当前链表的头节点的下标 初始的时候为-1表示没有节点  idx记录当前插入到数组的哪个地方。

void init(){
    head = -1;
    idx = 0;
}

void add(int x){
    // 在头节点的后面插入一个元素。
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void add_k(int k,int x){
    //在下标为k的元素的后面一个位置插入一个元素
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void remove(int k){
    // 删除下标为k的元素的后一个元素
    ne[k] = ne[ne[k]];
}

int main(){
    int m;
    scanf("%d",&m);
    init();
    while(m--){
        char d;
        int a,b;
        cin>>d;
        // 这里写的不清楚
        switch(d){
            case 'I':{
                //在k的后一个位置上插入
                cin>>a>>b;
                add_k(a-1,b);
            }break;
            case 'H':{
                //在头节点后面插入
                cin>>a;
                add(a);
            }break;
            case 'D':{
                //删除k的后一个元素  如果是0那么删除头节点。
                cin>>a;
                if(a) remove(a-1);
                else head = ne[head];
            }break;
        }
    }
    for(int i = head;i!=-1;i = ne[i]){
        cout<<e[i]<<" ";
    }


    return 0;
}

