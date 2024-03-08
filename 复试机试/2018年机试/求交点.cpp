//
// Created by Nino Neumann on 2024/3/7.
//

// 二维向量叉乘是面积
#include "iostream"
using namespace std;

int main(){
    int x1,y1,x2,y2,x3,y3,x4,y4;

    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    int k1 = x1 - x2, d1 = y1 - y2;
    int k2 = x3 - x4, d2 = y3 - y4;
    double a = (double)d1/k1;
    double b = (double)d2/k2;
    if(k1*d2-d1*k2 == 0) cout<<"Parallel or coincident\n";
    else{
        // 考虑了两条边都是斜的 a b都存在
        double x,y;
        if(k1 == 0) x = x1,y = b*(x-x3) + y3;
        else if(k2 == 0) x = x3,y = a*(x-x1) + y1;
        else x = (a*x1-b*x3+y3-y1)/(a-b),y = a*(x-x1)+y1;
        printf("%0.2lf %0.2lf\n",x,y);
    }

    return 0;
}

