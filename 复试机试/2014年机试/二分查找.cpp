//
// Created by Nino Neumann on 2024/3/6.
//

//
/*
 * 输入描述
第一行输入一个整数N（N<=10000）。
第二行输入N个升序整数。
第三行输入一个待查找的整数（必定在第二行中出现过）。
 *
 * 输出描述
输出二分查找该整数时，进行过多少次二分。
 *
 * */

#include<iostream>
using namespace std;
const int N = 1e5+100;

int nums[N];
int n,k;

int binary_search(int k){
    int l = 0, r = n-1;
    int res = 0;
    while(l<r){
        int mid = (l+r)>>1;
        res++;
        if(nums[mid]==k) return res;
        if(nums[mid]>k) r = mid;
        else l = mid+1;
    }
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i = 0; i < n; ++i)
        cin>>nums[i];
    cin>>k;

    cout<<binary_search(k)<<endl;

//    cout<<k<<endl;




    return 0;
}


