/*
长途电话每分钟计费
输入：
费率结构
一行：有24个整数 代表着每天不同时段的计费
电话记录
接下来的N行
每一行由 客户名字，时间，上线还是下线。
每个上线记录都与一个按照时间顺序排列的离线记录配对

这种题目一定要先把思路想好再代码实现
1、每条数据元素的存储：姓名string、时间int【4】、状态bool
2、数据的读入
3、数据整理：直接对这个数据元素进行sort 按照姓名从高到低，同姓名按照时间从低到高
4、创建一个stack 遍历每个用户的区间。
    判断当前stack top元素的状态
    为空，则判断当前元素是否为online 是则加入 否 则continue；
    top 为 online 当前为 offline 开始计算 最后将online排除
    top 为 online 当前为 online 将top排出 压入当前
    top 为 offline 当前为online
    对每一个用户当其为
*/
//
// Created by Nino Neumann on 2023/4/4.
//
// 奔溃啦aaaaa
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int n;
int rate_struct[24];
double spend_a_day;

int get_fee(string pre,string cur,double &fee){

    int pre_dd = stoi(pre.substr(3,2));
    int pre_hh = stoi(pre.substr(6,2));
    int pre_mm = stoi(pre.substr(9,2));
    int cur_dd = stoi(cur.substr(3,2));
    int cur_hh = stoi(cur.substr(6,2));
    int cur_mm = stoi(cur.substr(9,2));
    // 是否跨天
    int span = (cur_mm+cur_hh*60+cur_dd*60*24)-(pre_mm+pre_hh*60+pre_dd*60*24);
    while(pre_dd!=cur_dd || pre_hh!=cur_hh || pre_mm != cur_mm){
        fee += rate_struct[pre_hh];
        pre_mm++;
        if(pre_mm==60){
            pre_mm = 0;
            pre_hh++;
        }
        if(pre_hh==24){
            pre_hh=0;
            pre_dd++;
        }
    }
    return span;
}

struct info{
    string name;
    string time;
    string state;
    bool operator<(const info &a) const{
        return name==a.name?time<a.time:name<a.name;
    }
};
vector<info> customers;

int main(){

    for(int i = 0;i<24;++i) {
        scanf("%d",&rate_struct[i]);
        spend_a_day += rate_struct[i]*60;
    }
    scanf("%d",&n);
    for(int i = 0;i<n;++i){
        char name[21],time[14],state[10];
        scanf("%s%s%s",name,time,state);
        customers.push_back({name,time,state});
    }
    sort(customers.begin(),customers.end());
    for(int i = 0;i<n-1;){
        if(customers[i].state=="off-line"){
            i++;
            continue;
        }
        int j = i+1;
        string name = customers[i].name;
        string mo = customers[i].time.substr(0,2);
        printf("%s %s\n",name.c_str(),mo.c_str());
        double total = 0;
        while(customers[j].name==name){
            // 用j-1和j表示相邻的两个状态 四种情况 j-1==off j==off ;j-1==on j==on; j-1==off j==on; j-1==on j==off
            // 只有第四种情况是合法的 j+=2  其余的j++
            info pre = customers[j-1];
            info current = customers[j];
            double fee = 0;
            bool flag = 0;
            if(pre.state=="on-line" && current.state=="off-line"){
                // 计算单步结果
                int span = get_fee(pre.time,current.time,fee);

                fee/=100;
                total += fee;
                printf("%s %s %d $%.2lf\n",pre.time.substr(3,8).c_str(),current.time.substr(3,8).c_str(),span,fee);
                j+=2;  //
            }else {
                j++;
            }
        }
        printf("Total amount: $%.2lf\n",total);
        if(customers[j-1].name==customers[j].name)
            i = j-1;
        else
            i = j;
    }
    return 0;
}
