//
// Created by Nino Neumann on 2024/2/22.
//
#include <iostream>
using namespace std;
const int N = 128;
bool ht[N];
int main() {
    char c;
    int res = 0;
    while((c = getchar())!='\n') if(!ht[c]) res++,ht[c] = true;
    cout<<res<<endl;
}
// 64 位输出请用 printf("%lld")