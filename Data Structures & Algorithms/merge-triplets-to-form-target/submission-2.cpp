class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> st;
        bool a = false, b = false,c=false;
        for(auto it : triplets){
            if(it[0] > target[0] || it[1] > target[1] || it[2] > target[2]) continue;
            // for(int i=0;i<target.size();++i){
            //     if(it[i] == target[i]){
            //         //Insert index instead of elements as it can be duplicate 
            //         //Set does not allow duplicates
            //         st.insert(i);
            //     }
            // }
            // if(st.size() == 3) return true;

            //Optimal
            if(target[0] == it[0]) a=true;
            if(target[1] == it[1]) b=true;
            if(target[2] == it[2]) c=true;
            if(a && b && c) return true;
        }
        return false;
    }
};
