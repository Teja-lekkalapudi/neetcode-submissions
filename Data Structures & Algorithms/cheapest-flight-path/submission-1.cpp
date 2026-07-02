class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for(auto it : flights){
            //{node,wt}
            adjList[it[0]].push_back({it[1],it[2]});
        }
        // {k,{node,price}} -> because simple dijkshtra wont work
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        q.push({0,{src,0}});
        dist[src] = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int node = it.second.first;
            int price = it.second.second;
            if(steps > k) continue;
            for(auto ptr : adjList[node]){
                int adjNode = ptr.first;
                int edWt = ptr.second;
                if(price + edWt < dist[adjNode] && steps <= k){
                    dist[adjNode] = price + edWt;
                    q.push({steps+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
