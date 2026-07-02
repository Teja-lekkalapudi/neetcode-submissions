class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adjList;
    void dfs(string str,vector<string>& res){
        //Use reference 
       auto &pq = adjList[str];
        while(!pq.empty()){
            string it = pq.top();
            pq.pop();
            dfs(it,res);
        }
        res.push_back(str);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto it : tickets){
            adjList[it[0]].push(it[1]);
        }
        vector<string> res;
        dfs("JFK",res);
        reverse(res.begin(),res.end());
        return res;
    }   
};
