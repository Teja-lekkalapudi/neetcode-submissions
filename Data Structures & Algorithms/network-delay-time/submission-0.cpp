class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Create a adjacency List <node,time>
        vector<vector<pair<int,int>>> adjList(n+1);
        for(auto it : times){
            int src = it[0];
            int tar = it[1];
            int time = it[2];
            adjList[src].push_back({tar,time});
        }
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        //push src node in form {time,node}
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int time = it.first;
            for(auto it : adjList[node]){
                int adjNode = it.first;
                int edWt = it.second;
                if(time + edWt < dist[adjNode]){
                    dist[adjNode] = time+edWt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        int min_time = -1;
        //1-based indexing , 0th index is always 1e9
        for(int i=1;i<=n;++i){
            if(dist[i] != 1e9){
                min_time = max(min_time,dist[i]);
            }
            else return -1;
        }
        return min_time;
    }
};
