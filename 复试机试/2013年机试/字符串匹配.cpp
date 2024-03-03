//
// Created by Nino Neumann on 2024/3/3.
//
/*
 * 题目描述：对于主串M和模式串P，找到P在M中出现的所有子串的第一个字符在P中的位置。
 * P中第一个字符所在的位置为0。
 * 首行的数字表示有多少组字符串。
 *
 * 2
 * ababababa
 * ababa
 * aaa
 * aa
 *
 * */
#include<iostream>
#include<string>
using namespace std;

const int N = 1e6+10;
int ne[N];


int main(){
    int n;
    cin>>n;
    while(n--){
        string p,s;
        int n,m;
        cin>>s>>p;
        // 主串是s 模式串是p
        n = p.size();
        m = s.size();
        // cout<<n<<' '<<m<<endl;
        p = ' ' + p;
        s = ' ' + s;
        // 计算next数组
        for(int i = 2,j = 0;i<=n;++i){
            while(j && p[i]!=p[j+1]) j = ne[j];
            if(p[i]==p[j+1]) j++;
            ne[i] = j;
        }
        // 匹配数组
        for(int i = 1,j = 0;i<=m;++i){
            while(j && s[i]!=p[j+1]) j = ne[j];
            if(s[i]==p[j+1]) j++;
            if(j==n){
                cout<<i-n<<' ';
                j = ne[j];
            }
        }
        cout<<endl;
    }

    return 0;
}