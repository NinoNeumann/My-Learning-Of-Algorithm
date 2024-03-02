//
// Created by Nino Neumann on 2023/3/7.
//
//class Solution {
//public:
//    int numDecodings(string s) {
//        int n = s.length();
//        int f[n+1];
//        memset(f,0,sizeof f);
//
//        f[0] = 1;
//
//        for(int i = 1;i<=n;++i){
//            // int k = ;
//            if(s[i-1]!='0')f[i] += f[i-1];
//            if(i>=2 &&  s[i-2]!='0' && stoi(s.substr(i-2,2))<=26 ){
//                f[i] += f[i-2];
//            }
//
//        }
//        return f[n];
//    }
//};

// 二刷了
class Solution {
public:
    int f[101];
    int numDecodings(string s) {
        // fi表示以 si为结尾的编码可被映射的结果集合
        // 值表示 解码（集合）总数
        // 状态转换：当前si 和前一个 si-1能否被解码 如果能则 fi = fi-2 + 1 (理解一下为什么是fi-2)
        //          如果不能则 fi = fi-1
        int n = s.size();
        s = ' ' + s;
        f[1] = !(s[1]=='0');
        f[0] = 1;
        for(int i = 2;i<=n;++i){
            int check = stoi(s.substr(i-1,2));
            // cout<<check<<endl;
            if(s[i]!='0'){
                f[i] = f[i-1];
                if(check<=26 && check>=10) f[i] += f[i-2];
            }else{
                if(check==20 || check==10) f[i] += f[i-2];
            }
        }
        return f[n];
    }
};