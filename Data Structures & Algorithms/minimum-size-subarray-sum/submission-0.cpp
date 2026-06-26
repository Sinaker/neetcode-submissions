class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 2 sum similar
        int n = nums.size();
        if(nums[0]>=target) return 1;
        
        // below algo doesnt check for first element
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0]; // [0,i]

        for(int i = 1; i<n; i++) 
            prefixSum[i] = prefixSum[i-1] + nums[i];
        
        int ans = INT_MAX;
        for(int i = n-1; i >= 0; i--) {

    if(prefixSum[i] >= target)
        ans = min(ans, i + 1);

    int l = 0;
    int r = i - 1;
    int j = -1;

    while(l <= r) {
            int m = l + (r - l) / 2;

            if(prefixSum[i] - prefixSum[m] >= target) {
                j = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        if(j != -1)
            ans = min(ans, i - j);
    }
        return (ans==INT_MAX) ? 0 : ans;
    }
};