class Solution {
public:
//Check both for no cycles and one single component
//A valid tree is a single component
    // bool dfs(int node,vector<vector<int>>& adjList,vector<int>& visited,int parent){
    //     visited[node] = 1;
    //     for(auto it : adjList[node]){
    //         if(!visited[it]){
    //             if(!dfs(it,adjList,visited,node)) return false;
    //         }
    //         else{
    //             if(it != parent) return false;
    //         }
    //     }
    //     return true;
    // }
    int findUParent(int u,vector<int>& parent){
        if(parent[u] == u) return u;
        //Path compression for finding ultimate parent in O(1)
        return parent[u] = findUParent(parent[u],parent);
    }
    void unionBySize(int u,int v,vector<int>& parent,vector<int>& size){
        int uPar = findUParent(u,parent);
        int vPar = findUParent(v,parent);
        if(uPar == vPar) return ;
        if(size[uPar] < size[vPar]){
            parent[uPar] = vPar;
            size[vPar] += size[uPar];
        }
        else{
            parent[vPar] = uPar;
            size[uPar] += size[vPar];
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        //Finds a single component or not
        if (edges.size() != n - 1) return false;
        // vector<vector<int>> adjList(n);
        // for(auto it : edges){
        //     adjList[it[0]].push_back(it[1]);
        //     adjList[it[1]].push_back(it[0]);
        // }
        // vector<int> visited(n,0);
        // if(!dfs(0,adjList,visited,-1)) return false;
        // //Single Component checking
        // for(int i=0;i<n;++i){
        //     if(!visited[i]) return false;
        // }
        // return true;
        vector<int> parent(n+1);
        for(int i=0;i<=n;++i) parent[i]=i;
        vector<int> size(n+1,1);
        for(auto it : edges){
            int uPar = findUParent(it[0],parent);
            int vPar = findUParent(it[1],parent);
            if(uPar == vPar){
                //Finds a cycle 
                return false;
            }
            else{
                unionBySize(it[0],it[1],parent,size);
            }
            
        }
        return true;
        
    }
};
