class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) return stones[0];
        priority_queue<int> pq;
        for(int it : stones){
            pq.push(it);
        }
        while(pq.size() > 1){
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            int newStone = abs(stone1-stone2);
            pq.push(newStone);
        }
        return pq.top();
    }
};
