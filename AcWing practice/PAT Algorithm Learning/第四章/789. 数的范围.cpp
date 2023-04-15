//
// Created by Nino Neumann on 2023/4/15.
//
#include<iostream>
using namespace std;
const int N = 1e5+10;
int n,q;
int m[N];

// 二分查找

int bs_right(int nums[],int t){
    int r = n-1,l = 0;
    while(l<r){
        int mid = (l+r+1)>>1;
        if(nums[mid]<=t) l = mid;
        else r = mid-1;
    }
    // cout<<"targ: "<<t<<" right:"<<l<<" "<<r<<endl;
    if(nums[l]==t) return l;
    return -1;
}

int bs_left(int nums[],int t){
    int r = n-1,l = 0;
    while(l<r){
        int mid = (l+r)>>1;
        if(nums[mid]>=t) r = mid;
        else l = mid+1;
    }

    // cout<<"targ: "<<t<<" left:"<<l<<" "<<r<<endl;
    if(nums[l]==t) return l;
    return -1;
}

int main(){
    scanf("%d%d", &n,&q);
    for(int i = 0;i<n;++i)scanf("%d",&m[i]);
    for(int i = 0;i<q;++i){
        int temp;
        scanf("%d",&temp);
        int left = bs_left(m,temp);
        int right = bs_right(m,temp);
        cout<<left<<" "<<right<<endl;
    }
    return 0;
}