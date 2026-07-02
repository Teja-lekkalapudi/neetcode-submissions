class Solution {
public:
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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i=0;i<=n;++i) parent[i]=i;
        vector<int> size(n+1,1);
        vector<int> res(2);
        for(auto it : edges){
            int uPar = findUParent(it[0],parent);
            int vPar = findUParent(it[1],parent);
            if(uPar == vPar){
                res[0] = it[0];
                res[1] = it[1];
            }
            else{
                unionBySize(it[0],it[1],parent,size);
            }
        }
        return res;
    }
};
