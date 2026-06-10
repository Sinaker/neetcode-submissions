class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int maxi = nums[0];
        int secMaxi = 0;

        int mini = nums[0];
        int secMini = nums[0];

        for(int n : nums) {
            if(n>=maxi) {
                secMaxi = maxi;
                maxi = n;
            } else if(n>secMaxi) secMaxi = n;

            if(n<=mini) {
                secMini = mini;
                mini = n;
            } else if(n<secMini) secMini = n;
        }
        return maxi*secMaxi - mini*secMini;
    }
};