class Solution {
public:
    bool dfs_toposort(int node,vector<vector<int>>& adjList,vector<int>& visited,vector<int>& pathVisited,vector<int>& res){
        visited[node] = 1;
        pathVisited[node] = 1;
        for(auto it : adjList[node]){
            if(!visited[it]){
                if(!dfs_toposort(it,adjList,visited,pathVisited,res)) return false;
            }
            else{
                if(pathVisited[it]) return false;
            }
        }
        pathVisited[node] = 0;
        res.push_back(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
       int n = prereq.size();
        vector<vector<int>> adjList(numCourses);
        for(auto it : prereq){
            adjList[it[1]].push_back(it[0]);
        } 
        vector<int> visited(numCourses,0);
        vector<int> pathVisited(numCourses,0);
        vector<int> res;
        for(int i=0;i<numCourses;++i){
            if(!visited[i]){
                if(!dfs_toposort(i,adjList,visited,pathVisited,res)){
                    return {};
                }
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
