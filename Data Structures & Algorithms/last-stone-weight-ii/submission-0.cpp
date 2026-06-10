class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(auto stone : stones)
            maxHeap.push(stone);
        
        while(maxHeap.size()!=1) {
            int largest = maxHeap.top(); maxHeap.pop();
            int secLar = maxHeap.top(); maxHeap.pop();
            maxHeap.push(largest-secLar);
        }
        return maxHeap.top();
    }
};