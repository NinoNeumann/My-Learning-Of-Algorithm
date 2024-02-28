//
// Created by Nino Neumann on 2024/2/23.
//
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end()); // 从小到大一次排序
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0;i<nums.size();++i){
            int start = i+1,end = nums.size()-1;
            while(start<end){
                int s = nums[start]+nums[end]+nums[i];
                if(abs(target-s)<abs(target-ans)) ans = s;
                if(s<target) start++;
                else if(s>target) end--;
                else return ans;
            }
        }
        return ans;
    }
};