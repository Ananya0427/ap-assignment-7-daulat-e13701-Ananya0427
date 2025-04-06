class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pq(piles.begin(), piles.end());

        while (k--) {
            int top = pq.top();
            pq.pop();
            top -= top / 2; 
            pq.push(top);
        }

        int total = 0;
        while (!pq.empty()) {
            total += pq.top();
            pq.pop();
        }

        return total;
    }
};
