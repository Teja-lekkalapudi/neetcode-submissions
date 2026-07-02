class Solution {
public:

    string encode(vector<string>& strs) {
        string mstr = "";
        for(auto it : strs){
            mstr = it + '.' + mstr;
        }
        return mstr;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int n = s.size();
        string str = "";
        for(int i=0;i<n;++i){
            if(s[i] != '.'){
                str += s[i];
            }
            else{
                res.push_back(str);
                str = "";
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
