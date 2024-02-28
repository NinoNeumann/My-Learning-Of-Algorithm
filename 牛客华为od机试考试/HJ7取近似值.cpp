//
// Created by Nino Neumann on 2024/2/22.
//
#include <iostream>
using namespace std;
float c;
int main() {
    cin>>c;
    cout<<(int)(((int)(c*10)%10>=5)?c+1:c);
}
// 64 位输出请用 printf("%lld")