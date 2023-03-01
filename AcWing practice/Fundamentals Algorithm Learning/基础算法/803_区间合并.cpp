//
// Created by Nino Neumann on 2023/3/1.
//
// 我自己的思路：给一个结构体 然后排序然后想某一题 合并区间
// 并查集

#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5;
struct range{
    int l,r;
    bool operator< (const range &t) const{
        return l<t.l;
    }
};
range ranges[N];
//vector<range> res;

int main(){
    int n;
    int res = 1;

    cin>>n;
    for(int i = 0;i<n;++i) scanf("%d%d",&ranges[i].l,&ranges[i].r);
    sort(ranges,ranges+n);
//    int ed = ranges[0].r,st = ranges[0].l;
    int maxr = ranges[0].r;
    for(int i = 1;i<n;++i){
        // 遇到问题：依次枚举 类似贪心的做法不行 缺少一些状态来告知我当前区间的合并状况
//        if(ranges[i].l>ed){
//            res++;
//            st = ranges[i].l;
//            ed = ranges[i].r;
//        }else if(ranges[i].l<ed){
//            ed = ranges[i].r;
//        }
        if (ranges[i].l<=maxr) maxr = max(maxr,ranges[i].r);
        else{
            res++;
            maxr = ranges[i].r;
        }

    }
    cout<<res<<endl;
    return 0;
}


// 下面的代码为啥不能AC
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//const int N = 2e5;
//struct range{
//    int l,r;
//    bool operator< (const range &t) const{
//        return l<t.l;
//    }
//};
//range ranges[N];
////vector<range> res;
//
//int main(){
//    int n;
//    int res = 0;
//
//    cin>>n;
//    for(int i = 0;i<n;++i) scanf("%d%d",&ranges[i].l,&ranges[i].r);
//    sort(ranges,ranges+n);
//    int ed = ranges[0].r,st = ranges[0].l;
//    for(int i = 1;i<n;++i){
//        // 遇到问题：依次枚举 类似贪心的做法不行 缺少一些状态来告知我当前区间的合并状况
//        if(ranges[i].l>ed){
//            res++;
//            st = ranges[i].l;
//            ed = ranges[i].r;
//        }else if(ranges[i].l<ed){
//            ed = ranges[i].r;
//        }
//
//    }
//    cout<<res<<endl;
//    return 0;
//}