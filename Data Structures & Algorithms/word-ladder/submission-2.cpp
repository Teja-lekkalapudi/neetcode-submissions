class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            int n = word.size();
            q.pop();
            if(word == endWord) return level;       
            for(int i=0;i<n;++i){
                char ch = word[i];
                for(int j=0;j<26;++j){
                    word[i] = char(j + 'a');
                    if(st.find(word) != st.end()){
                        q.push({word,level+1});
                        st.erase(word);
                    }
                }
                word[i] = ch;
            }
        }
        return 0;
    }
};
