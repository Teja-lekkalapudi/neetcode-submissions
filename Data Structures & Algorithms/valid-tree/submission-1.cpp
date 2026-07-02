class Solution {
public:
//Check both for no cycles and one single component
//A valid tree is a single component
    bool dfs(int node,vector<vector<int>>& adjList,vector<int>& visited,int parent){
        visited[node] = 1;
        for(auto it : adjList[node]){
            if(!visited[it]){
                if(!dfs(it,adjList,visited,node)) return false;
            }
            else{
                if(it != parent) return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto it : edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        vector<int> visited(n,0);
        if(!dfs(0,adjList,visited,-1)) return false;
        //Single Component checking
        for(int i=0;i<n;++i){
            if(!visited[i]) return false;
        }
        return true;
    }
};
