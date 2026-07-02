class Solution {
public:
    // Explanation : 
        // If count = 3 for number num = 5, it means:
        // 👉 We have three 5s
        // So we must start 3 different groups with 5.
        // Because every card must belong to some group.

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        map<int,int> freq;
        for(int i=0;i<n;++i){
            freq[hand[i]]++;
        }
        for(auto it : freq){
            int num = it.first;
            int cnt = it.second;
            if(cnt > 0){
                for(int i=0;i<groupSize;++i){
                    if(freq[num+i] < cnt){
                        return false;
                    }
                    freq[num+i] -= cnt;
                }
            }
        }
        return true;
    }
};
