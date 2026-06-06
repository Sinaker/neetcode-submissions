class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int maxi = INT_MIN;
        int secMaxi = INT_MIN;

        int mini = INT_MAX;
        int secMini = INT_MAX;

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