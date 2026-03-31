class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, 0, target);
    }
    int helper(vector<int>&nums, int start, int target) {
        if(start==nums.size())
            return target==0;
        
        return helper(nums, start + 1, target - nums[start]) + helper(nums, start+1, target + nums[start]);
        
    }
};
