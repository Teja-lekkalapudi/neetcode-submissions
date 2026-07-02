class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        // store <distance , index >
        priority_queue<pair<int,int>> pq;
        for(int it=0;it<n;++it){
            int x1 = points[it][0];
            int y1 = points[it][1];
            int dist = x1*x1 + y1*y1;
            pq.push({dist,it});
            // Removing the farthest
            if(pq.size() > k) pq.pop();
        }
        // Store the coordinates
        vector<vector<int>> res;
        // As the priority queue is not iterable so pop each element out and store
        while(!pq.empty()){
            int ind = pq.top().second;
            pq.pop();
            res.push_back(points[ind]);
        }
        return res;
    }
};
