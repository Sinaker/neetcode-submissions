class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) return myPow(1/x, -n);
        if(n==0) return 1;
        if(n==1) return x;


        double half = myPow(x, n/2);

        // odd
        if(n%2)
            return x*half*half;
        // eve
        return half*half;

    }
};
