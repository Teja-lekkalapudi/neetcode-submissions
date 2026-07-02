class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> indegree(n, 0);
        queue<int> q;
        vector<int> list;

        // Compute indegrees
        for (int i = 0; i < n; i++) {
            for (int next : adj[i])
                indegree[next]++;
        }

        // Add all nodes with indegree 0 
        // into the queue
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        // Kahn?s Algorithm (BFS)
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            list.push_back(top);
            for (int next : adj[top]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return list;
    }
    vector<vector<int>> findOrder(vector<string>& words,vector<bool>& present){
        int n = words.size();
        vector<vector<int>> adjList(26);

        for (auto &w : words)
            for (char c : w)
                present[c - 'a'] = true;

        for(int i=0;i<n-1;++i){
            string str1 = words[i];
            string str2 = words[i+1];
            int len = min(str1.size(),str2.size());
            if(str1.size() > str2.size() && str1.substr(0,len) == str2.substr(0,len)){
                return {};
            }
            for(int j=0;j<len;++j){
                if(str1[j] != str2[j]){
                    adjList[str1[j]-'a'].push_back(str2[j]-'a');
                    break;
                }
            }

        }
        return adjList;
    }
    string foreignDictionary(vector<string>& words) {
        vector<bool> present(26, false);
        vector<vector<int>> adjList = findOrder(words,present);
        vector<int> topo = topoSort(adjList);

        //cycle check
        int countPresent = count(present.begin(), present.end(), true);
        if (topo.size() < countPresent) return ""; 

        string result = "";
        for(auto it : topo){
            if(present[it])           // only include letters that exist
                result += char(it + 'a');
        }

        return result;
    }
};
