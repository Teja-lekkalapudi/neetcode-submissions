class Solution {
public:
    string convert_to_low(string s){
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
        return str;
    }
    bool isPalindrome(string s) {
        string str = convert_to_low(s);
        //palindrome logic , considering each letter as a middle of palindrome and expanding outwards
        int n = str.size();
        int mid = n >> 1;
        //odd length palindrome 
        int l = mid;
        int r = mid;
        if(n&1){
            while(l >= 0 && r < n){
                if(str[l] == str[r]){
                    l--;r++;
                }
                else return false;
            }
        }
        else{
            l = mid-1;
            r = mid;
            while(l >= 0 && r < n){
                if(str[l] == str[r]){
                    l--;r++;
                }
                else return false;
            }
        }
        return true;

    }
};
