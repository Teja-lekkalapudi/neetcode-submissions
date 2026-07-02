#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string mstr = "";
        for (auto &it : strs) {
            mstr += to_string(it.size()) + "#" + it;
        }
        return mstr;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int n = s.size();
        int i = 0;

        while (i < n) {
            int j = i;

            // find '#'
            while (s[j] != '#') j++;

            // length part
            int len = stoi(s.substr(i, j - i));

            j++; // move after '#'

            // take string of length len
            res.push_back(s.substr(j, len));

            // jump to next encoded block
            i = j + len;
        }

        return res;
    }
};
