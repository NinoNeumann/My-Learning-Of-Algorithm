//
// Created by Nino Neumann on 2024/3/6.
//

// acwing 1506. 中位数

// 给定一个整数序列，求中位数。

#include "iostream"
#include "algorithm"
using namespace std;
const int N = 3e5;

int nums[N];

int main(){
    int n;
    while(cin>>n && n){
        for (int i = 0; i < n; ++i) cin>>nums[i];
        sort(nums,nums+n);
        cout<<nums[n-1>>1]<<endl;
    }

    return 0;
}