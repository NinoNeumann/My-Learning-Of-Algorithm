//
// Created by Nino Neumann on 2023/3/11.
//
class Solution {
public:
    int rob(vector<int>& nums) {

        int f1[nums.size()+1];// 两种情况
        int f2[nums.size()+1];
        memset(f1,0,sizeof f1);
        memset(f2,0,sizeof f2);
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        for(int i = 0;i<nums.size()-1;++i){
            int mx = 0;
            for(int k = 0;k<=i-2;++k){
                mx = max(f1[k],mx);
            }
            f1[i] = mx+nums[i];
        }
        for(int i = 1;i<nums.size();++i){
            int mx = 0;
            for(int j = 1;j<=i-2;++j){
                mx = max(f2[j],mx);
            }
            f2[i] = mx+nums[i];

        }
        int mx = 0;
        for(int i = 0;i<nums.size();++i){
            mx = max(mx,max(f1[i],f2[i]));

        }
        // for(int i = 1;i<=nums.size()-1;++i)
        //     cout<<"f2 "<<i<<"  "<<f2[i]<<endl;
        return mx;
    }
};
// 主要思想就是将一个循环的排列转换为两个不循环的排列。
// 为什么要转换为两个不循环排列