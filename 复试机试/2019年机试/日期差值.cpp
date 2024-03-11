//
// Created by Nino Neumann on 2024/3/8.
//
// 输入日期格式：YYYYMMDD，求与20190205相隔天数
#include "iostream"
#include "string"
using namespace std;

typedef pair<int,int> PII;

string start = "20190205";
int d[8];
int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

// 我们始终求一个小的日期到大的日期的差值 让小的日期的月份始终向前加到 下一年的大的日期的月份

PII get_year(int a,int b){
    int year_cnt = 0;
    int ryear_cnt = 0;
    if(a<b) swap(a,b);
    year_cnt = a-b;
    for(int i = b;i!=a;++i){
        if(i%400==0 || (i%4==0 && i%100))
            ryear_cnt++;
    }
    return {year_cnt,ryear_cnt};
}

int get_days(int a_m,int a_d,int b_m,int b_d){
    int res = 0;

    return 0;
}

int main(){
    string s;
    cin>>s;
    int year_a = stoi(s.substr(0,4));
    int month_a = stoi(s.substr(4,2));
    int day_a = stoi(s.substr(6,2));
    int year_b = 2019;
    int month_b = 2;
    int day_b = 5;
    if(year_a<year_b)
        swap(year_a,year_b),
        swap(month_a,month_b),
        swap(day_a,day_b);

    // b日期始终小于a日期
    int k_days = get_days()


    return 0;
}
