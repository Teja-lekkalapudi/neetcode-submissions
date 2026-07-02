class Solution {
public:
    int find(int node,vector<int>& Parent) {
        if (Parent[node] != node) {
            Parent[node] = find(Parent[node],Parent);
        }
        return Parent[node];
    }

    bool unionSets(int u, int v,vector<int>& Parent,vector<int>& Size) {
        int pu = find(u,Parent), pv = find(v,Parent);
        if (pu == pv) return false;
        if (Size[pu] < Size[pv]) swap(pu, pv);
        Size[pu] += Size[pv];
        Parent[pv] = pu;
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> Parent(n+1);
        for(int i=0;i<=n;++i) Parent[i]=i;
        vector<int> Size(n+1,1);
        //Store every edge between every possible nodes
        //distance,node1,node2
        vector<vector<int>> edges;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back({dist,i,j});              
            }
        }
        sort(edges.begin(),edges.end());
        int res = 0;
        for(auto it : edges){
            int dist = it[0];
            int u = it[1];
            int v = it[2];
            if(unionSets(u,v,Parent,Size)){
                res += dist;
            }
        }
        return res;
    }
};
