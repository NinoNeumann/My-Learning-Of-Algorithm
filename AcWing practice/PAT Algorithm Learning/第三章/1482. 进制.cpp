#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL N = 1e16;

int get(char c){
    if(c<='9') return c-'0';
    else return c-'a'+10;
}


LL convert(string a,LL radix){
    LL res = 0;
    LL c = 1;
    for(int i = a.length()-1;i>=0;--i){
        // if((double)res + (get(a[i])*c) > 1e16) return 1e18;
        // cout<<(double)res + (get(a[i])*c)<<"  ";
        res += (get(a[i])*c);
        c *= radix;
        // cout<<"  "<<res<<endl;
        if(res>1e16) return 1e16;
        if(res<0)return 1e16;

    }
    // cout<<res<<endl;
    return res;
}

int main(){
    string a,b;
    int tag,radix;
    cin>>a>>b>>tag>>radix;
    if(tag==2) swap(a,b);
    LL a_n = convert(a,radix);
    // cout<<"a_: "<<a_n<<endl;

    // 二分的模板
    LL l = 1,r = a_n+1;

    for (auto c : b) l = max(l, (LL)get(c) + 1);
    while(l<r){
        LL mid = (l+r)>>1;
        if(convert(b,mid)>=a_n) r = mid;
        else l = mid+1;
    }
    if(convert(b,r)==a_n) cout<<r<<endl;
    else cout<<"Impossible\n";
    // cout<<convert(b,r)<<endl;
    return 0;
}