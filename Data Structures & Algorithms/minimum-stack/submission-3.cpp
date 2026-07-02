class MinStack {
public:
    long long mini;
    stack<long long> st;
    MinStack() {
        mini = (long long)1e18;
    }
    
    void push(int val) {
        long long new_val = val;
        if(val < mini ){
            new_val = 2LL*val - mini;
            mini = val;
        }
        st.push(new_val);
    }
    
    void pop() {
        long long pEle = st.top();
        st.pop();
        if(pEle < mini){
            mini = 2*mini - pEle;
        }
    }
    
    int top() {
        long long pEle = st.top();
        if(pEle < mini)
            return  (int)mini;
        return (int)pEle;
    }
    
    int getMin() {
        return (int)mini;
    }
    
};
