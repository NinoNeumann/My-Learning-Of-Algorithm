//
// Created by Nino Neumann on 2024/2/22.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> sentence;
int main() {
    string t;
    while(cin>>t) sentence.push_back(t);
    cout<<sentence[sentence.size()-1];
    for(int i = sentence.size()-2;i>=0;--i)cout<<' '<<sentence[i];
}
// 64 位输出请用 printf("%lld")
