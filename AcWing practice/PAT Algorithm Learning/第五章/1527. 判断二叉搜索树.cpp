//
// Created by Nino Neumann on 2023/4/19.
//
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;



const int N = 1e3+10;
int preorder[N],postorder[N],inorder[N];
int cnt;
int n;


bool build(int il,int ir,int pl,int pr,int type){
    bool res = true;
    int root = preorder[pl];
    int k = -1;
    if(il>ir) return res; //  正常结束了
    if(type==0){
        // 二分查找左边界 升序数组中
        // for (k = il; k <= ir; k ++ )
        //     if (inorder[k] == root)
        //         break;
        // if (k > ir) return false;
        int l = il,r = ir;
        while(l<r){
            int mid = (r+l)>>1;
            if(inorder[mid]>=root)r = mid;
            else l = mid+1;
        }
        if(inorder[l]==root) k = l;
        else return false;
    }else{
        // 二分查找右边界 降序数组中
        // for (k = ir; k >= il; k -- )
        //     if (inorder[k] == root)
        //         break;
        // if (k < il) return false;
        int l = il,r = ir;
        while(l<r){
            int mid = (r+l+1)>>1;
            if(inorder[mid]>=root) l = mid;
            else r = mid-1;
        }
        if(inorder[l]==root) k = l;
        else return false;
    }

    if(!build(il,k-1,pl+1,pl+1+(k-1-il),type)) res = false;
    if(!build(k+1,ir,pl+1+(k-1-il)+1,pr,type)) res = false;
    postorder[cnt++] = root;
    return res;



}

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;++i){
        scanf("%d",&preorder[i]);
        inorder[i] = preorder[i];
    }
    sort(inorder,inorder+n);
    if(build(0,n-1,0,n-1,0)){
        // 这个树不是镜像并且存在  输出YES 和postorder序列
        printf("YES\n%d",postorder[0]);
        for(int i = 1;i<n;++i) printf(" %d",postorder[i]);
    } else{
        reverse(inorder,inorder+n);
        cnt = 0; // 一定要注意cnt的重置
        if(build(0,n-1,0,n-1,1)){
            printf("YES\n%d",postorder[0]);
            for(int i = 1;i<n;++i) printf(" %d",postorder[i]);
        }else{
            printf("NO\n");
        }
    }


    return 0;
}
