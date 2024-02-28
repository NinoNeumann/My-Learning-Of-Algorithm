//
// Created by Nino Neumann on 2023/6/6.
//
#include<iostream>
using namespace std;


const int N = 100;
int arrary[] = {4,2,2,3,3,3,4,5,6,7,8,4,4,3,2,4};
// 覆盖方法
void delete_x(int *arr,int x,int size){
    int k = 0;
    for(int i = 0;i<size;++i){
        if(arr[i]!=x){
            arr[k] = arr[i];
            k++;
        }
    }
}
int main(){

    delete_x(arrary,4,16);



    return 0;
}

