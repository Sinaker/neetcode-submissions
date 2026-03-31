class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + target) % 2 != 0 || sum < abs(target)) return 0;

        int newTarget = (sum + target)/2;

        vector<vector<int>> memo(nums.size(), vector<int>(newTarget+1, -1));
        return helper(nums, 0, newTarget, memo); // 0/1 Knapsack
    }
    int helper(vector<int>&nums, int start, int target, vector<vector<int>>& memo) {
        if(start==nums.size()) return target==0; //found one way
        if(memo[start][target] != -1) return memo[start][target];

        int take = 0;
        if (nums[start] <= target)
            take = helper(nums, start+1, target - nums[start], memo);
        int skip = helper(nums, start+1, target, memo);
        
        return memo[start][target] = take + skip;
        
    }
};
