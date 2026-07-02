class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char,int> mpp;
        for(int i=0;i<n;++i){
            mpp[s[i]] = i;
        }
        vector<int> res;
        int start = 0;
        int end = 0;
        for(int i=0;i<n;++i){
            start++;
            end = max(end , mpp[s[i]]);
            if(i == end){
                res.push_back(start);
                start=0;
            }
        }
        return res;
    }
};
