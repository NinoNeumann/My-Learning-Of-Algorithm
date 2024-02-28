//
// Created by Nino Neumann on 2023/4/28.
//
#include<iostream>
#include<cstring>
#include<ctype.h>
using namespace std;


int main(){
    string str;
    while(getline(cin,str),str!="ENDOFINPUT"){
        if(str=="START" || str=="END") continue;
        for(int i = 0;i<str.length();++i)
            if(isalpha(str[i])) str[i] -= 5, str[i] = str[i]<'A'? str[i]-'A'+'Z'+1:str[i];
        cout<<str<<endl;
    }
    return 0;
}