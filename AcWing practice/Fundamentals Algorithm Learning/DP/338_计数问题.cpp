//
// Created by Nino Neumann on 2023/3/4.
//
// 对每一个数字区间的每一个数字进行遍历【肯定会超时蛤别想了】
#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;


const int N = 100;


int power10(int s){
    int res = 1;
    while(s--){
        res *= 10;
    }
    return res;
}


int get(vector<int> num,int l,int r){
    // 计算从l~r位置的数值大小 也就是 abc这个i（i=3）位 数值
    int res = 0;
    for(int i = l;i<=r;++i){
        res = res*10 + num[i];
    }
    return res;
}

int count_num(int k,int x){
    int res = 0;
    if(!k)return 0;
    // 计算从1~k 上位数字为i的数量
    vector<int> num;
    while(k){
        num.push_back(k%10);
        k/=10;
    }
    reverse(num.begin(),num.end());
    // cout<<" num ";
    // for(auto x:num)cout<<x<<" ";
    // cout<<endl;
    int n = num.size(); // 记录k的位数
    for(int i = 0;i<n;++i){
        int l,r;
        l = get(num,0,i-1); // 计算高位从0~abc-1
        r = power10(n-1-i);
        // cout<<" l:"<<l<<endl;
        // 这个部分计算 000~abc-1的情况
        if(!x) res += (l-1)*r;
        else res += l*r;
        //  下面计算当前i位达到极限的情况
        if(num[i]==x) res = res + 1 + get(num,i+1,n-1);

        if(num[i]>x) res += r;  // abcd 4-2
    }
    return res;
}

int main(){
    int a,b;
    while(cin>>a>>b, a || b){
        if(a>b)swap(a,b);
        for(int i = 0;i<10;++i)
            cout<<count_num(b,i)-count_num(a-1,i)<<" ";
        // cout<<count_num(b,i)<<" ";
        cout<<endl;
    }
    return 0;
}

