class Solution {
public:
    void dfs(int node,vector<vector<int>>& adjList,vector<int>& visited){
        visited[node]=1;
        for(auto it : adjList[node]){
            if(!visited[it]){
                dfs(it,adjList,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int count=0;
        vector<vector<int>> adjList(n);
        vector<int> visited(n,0);
        for(auto it : edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;++i){
            if(!visited[i]){
                count++;
                dfs(i,adjList,visited);
            }
        }
        return count;
    }

};
