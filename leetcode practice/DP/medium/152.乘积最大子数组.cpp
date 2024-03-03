class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = 0x9fffffff;
        int n = nums.size();
        vector<int> f(2,1);
        for(int i = 1;i<=n;++i){
            if(nums[i-1]>0){
                // 计算最大值
                f[0] = max(nums[i-1]*f[0],nums[i-1]);
                f[1] = min(nums[i-1]*f[1],nums[i-1]);
            }else{
                int pre_f0 = f[0];
                int pre_f1 = f[1];
                // 这里使用了优化写法，将f从2*n O(n) 的空间开销减少到了O(1) [以下是原写法]
//                f[i][0] = max(nums[i-1]*f[i-1][1],nums[i-1]);
//                f[i][1] = min(nums[i-1]*f[i-1][0],nums[i-1]);
                f[0] = max(nums[i-1]*pre_f1,nums[i-1]);
                f[1] = min(nums[i-1]*pre_f0,nums[i-1]);
            }
            res = max(res,max(f[0],f[1]));
        }


        return res;
    }
};