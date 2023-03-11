//
// Created by Nino Neumann on 2023/3/9.
//
class Solution {
public:
    int rob(vector<int>& nums) {
        int f[nums.size()+1];
        if(nums.size()==2) return max(nums[0],nums[1]);
        else if(nums.size()==1) return nums[0];
        memset(f,0,sizeof f);
        f[0] = nums[0];
        f[1] = nums[1];

        for(int i = 2;i<nums.size();++i){
            int mx = 0;
            for(int j = 0;j<=i-2;++j){
                mx = max(mx,f[j]);
            }
            f[i] = mx + nums[i];
        }
        // cout<<f[nums.size()-1];
        int mx = 0;
        for(int i = 0;i<nums.size();++i)mx = max(mx,f[i]);
        return mx;
    }
};