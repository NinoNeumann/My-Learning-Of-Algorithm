#include<iostream>
using namespace std;

const int N = 5010;
int g[N][N];



int main(){
    int n,r;
    // 由于后面在计算前缀和的时候需要保证可计算范围得是个正数 要不然for循环无法进行
    cin>>n>>r;
    r = min(5001, r); // 因为r最大可以取 10^9 遇到一些特殊的值的时候可以将r取一个固定上界。
    int max_x = N-9,max_y = N-9;
    for(int i = 0,x,y,w;i<n;++i){
        cin>>x>>y>>w;
        // x++,y++;

        g[x+1][y+1] += w;
        // cout<<g[x][y]<<endl;
        // max_x = max(max_x,x+1),max_y = max(max_y,y+1);
    }
    // cout<<max_x<<" " <<" " <<max_y<<endl;
    int res = 0;
    for(int i = 1;i<=max_x;++i)
        for(int j = 1;j<=max_y;++j)
            g[i][j] += g[i-1][j]+g[i][j-1]-g[i-1][j-1];

    for(int i = 1;i<=max_x-r+1;++i)
        for(int j = 1;j<=max_y-r+1;++j)
            res = max(res,g[i+r-1][j+r-1]+g[i-1][j-1]-g[i+r-1][j-1]-g[i-1][j+r-1]);
    // for(int i = r;i<=max_x;++i)
    //     for(int j = r;j<=max_y;++j)
    //         res = max(res,g[i][j]-g[i-r][j]-g[i][j-r]+g[i-r][j-r]);
    cout<<res<<endl;


    return 0;
}