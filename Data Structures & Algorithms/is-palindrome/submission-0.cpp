class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char ch : s){
            if(isalnum(ch)){
                if(ch >= 'A' && ch <= 'Z'){
                    int diff = 32;
                    ch += diff;
                    
                }
                str += ch;
            }
        }
        int n = str.size();
        int l=0;
        int r=n-1;
        while(l <= r){
            if(str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
