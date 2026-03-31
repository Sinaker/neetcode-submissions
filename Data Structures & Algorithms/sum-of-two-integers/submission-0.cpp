class Solution {
public:
    int getSum(int a, int b) {
        if(b==0)
            return a;
        // If we think in terms of bits XOR can handle 0 + 1 combination
        // Only place it will struggle is 00 and 11
        // Carry can be that And
        // Left shift Carry, then perform add again, until carry is 0

        int xorAns = a ^ b;
        int carry = a & b;
        carry <<=1; // left shift
        return getSum(xorAns, carry);
    }
};
