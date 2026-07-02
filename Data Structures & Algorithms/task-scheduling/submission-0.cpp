class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mpp;
        for(auto it : tasks){
            mpp[it]++;
        }
        priority_queue<int> pq;
        for(auto it : mpp){
            pq.push(it.second);
        }
        int time = 0;
        queue<pair<int,int>> q;
        while(!pq.empty() || !q.empty()){
            time++;
            if(pq.empty()){
                // No need to wait until the time becomes q.front().second 
                // Just start from that time , enough!!
                time = q.front().second;
            }
            else{
                int cnt = pq.top()-1;
                pq.pop();
                // if count == 0 then that task is done,no need to add it in queue.
                if(cnt > 0){
                    q.push({cnt,time+n});
                }
            }
            // Now nothing is in pq , i.e, all tasks are waiting , 
            // if we find a task that is ready to execute then we put again in to pq;
            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
