//
// Created by Nino Neumann on 2023/3/1.
//
// 需要数论知识
// A^B的所有的约数之和
// 公式：
// 如何快速算 p0+p1+。。。pk-1 有公式（但是不是重点）
#include<iostream>
using namespace std;
typedef long long LL;
const int mod = 9901;


int qmi(int a,int k,int q){
    int res = 1;
    while (k){
        if(k&1) res = (res * (LL)a) % q;
        a = ((LL)a * a) % q;
        k >>= 1;
    }
    return res;
}

int sum(int a,int k){
    if(k==1) return 1;
    if(k%2==0) (1+qmi(a,k/2,mod)) * sum(a,k/2,mod) % mod;
    return (sum(a,k-1,mod)+qmi(a,k-1,mod)) % mod;
}


int main(){
    int a,b;
    cin>>a>>b;
    //分解质因数
    for(int i = 2;i*i<=a;++i){
        if(a % i == 0){
            // 说明i是a的一个质因子
            int s = 0;
            while(a % i == 0){
                a /= i, s++;
            }
            res = res * sum(i, b * s + 1);
        }
    }
    if(a > 1) res = res * sum(a, b+1) % mod;
    if(a == 0) res = 0;
    cout<<res<<endl;
    return 0;

}

/*
 * 这个解法很不错！很清晰
#include<iostream>
#include<unordered_map>
using namespace std;
typedef long long LL;

const int mod = 9901;
int A, B;

//保存质因子以及出现的次数
unordered_map<int, int> primes;

//试除法质因子分解
void divide(int n) {
    for(int i = 2; i <= n / i; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                primes[i]++;
                n /= i;
            }
        }
    }
    if(n > 1) {
        primes[n]++;
    }
}

//快速幂
int qmid(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        b >>= 1;
    }
    return res;
}

//p0 + .. + pk-1
int sum(int p, int k) {
    if(k == 1) return 1;  //边界
    if(k % 2 == 0) {
        return (LL)(qmid(p, k / 2) + 1) * sum(p, k / 2) % mod;
    }
    return (qmid(p, k - 1) + sum(p, k - 1)) % mod;
}

int main(){
    cin >> A >> B;

    //对A分解质因子
    divide(A);

    int res = 1;
    for(auto it : primes) {
        //p是质因子，k是质因子的次数
        int p = it.first, k = it.second * B;
        // res要乘上每一项, 注意这里是k + 1
        res = (LL)res * sum(p, k + 1) % mod;
    }
    if(!A) res = 0;

    cout << res << endl;

    return 0;
}
 * */
