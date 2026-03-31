class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Prefix Sum + HashMap

        // Step 1: Build prefix sum array (this part is fine)
        for(int i = 1; i < nums.size(); i++)
            nums[i] += nums[i-1]; // nums[i] now stores sum of [0..i]

        unordered_map<int, int> subArrFreq;
        subArrFreq[0] = 1; // IMPORTANT: handles subarrays starting from index 0

        int ans = 0;

        // ❌ WRONG (your version):
        // You filled the map with ALL prefix sums beforehand.
        // That includes FUTURE prefix sums, which leads to overcounting.
        //
        // for(int n : nums)
        //     subArrFreq[n]++;

        // ✅ FIX:
        // Iterate left → right and build the map ON THE GO
        for(int n : nums) {

            // We want: prefix[j] - prefix[i] = k
            // => prefix[i] = prefix[j] - k
            // So check if (current_prefix - k) existed BEFORE
            if(subArrFreq.count(n - k))
                ans += subArrFreq[n - k];

            // After using current prefix, add it to map
            // so it can help future elements
            subArrFreq[n]++;
        }

        return ans;
    }
};