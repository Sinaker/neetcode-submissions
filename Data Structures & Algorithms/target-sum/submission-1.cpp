class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2) return 0;

        vector<vector<int>> memo(nums.size(), vector<int>(target+1, -1));
        return helper(nums, 0, sum/2, memo); // 0/1 Knapsack
    }
    int helper(vector<int>&nums, int start, int target, vector<vector<int>>& memo) {
        if(start==nums.size()) return target==0; //found one way
        if(memo[start][target] != -1) return memo[start][target];

        int take = helper(nums, start+1, target - nums[start], memo);
        int skip = helper(nums, start+1, target, memo);
        
        return memo[start][target] = take + skip;
        
    }
};
