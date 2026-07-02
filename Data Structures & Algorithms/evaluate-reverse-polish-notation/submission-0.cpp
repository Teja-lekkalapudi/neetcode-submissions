class Solution {
public:
    bool isOperator(string ch){
        if(ch == "+" || ch == "-" || ch == "*" || ch == "/"){
            return true;
        }
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        int i = 0;
        int n = tokens.size();
        stack<int> st;
        while(i < n){
            if(isOperator(tokens[i])){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int eval = 0;
                string tok = tokens[i];
               if (tok == "+") st.push(a + b);
                else if (tok == "-") st.push(a - b);
                else if (tok == "*") st.push(a * b);
                else st.push(a / b);
            }
            else {
                st.push(stoi(tokens[i]));
            }
            i++;
        }
        return st.top();
    }
};
