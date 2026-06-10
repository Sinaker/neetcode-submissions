class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Prefix Sum + 2 Sum
        for(int i = 1; i<nums.size(); i++)
            nums[i] += nums[i-1]; // [0,i] sum

        unordered_map<int, int> subArrFreq;
        subArrFreq[0] = 1; // One soln with 0 exists
        for(int n : nums)
            subArrFreq[n]++;
        
        int ans = 0;
        for(int n : nums) {
            if(subArrFreq.count(n-k))
                ans += subArrFreq[n-k];
        }
        return ans;
    }
};