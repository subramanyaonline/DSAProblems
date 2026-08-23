class MinStack {
    vector<int> st ; 
    stack<int> minst ; 
public:
    MinStack() {

    }
    
    void push(int value) {
        st.push_back(value) ; 
        if(minst.empty() || value < st[minst.top()] ) {
            minst.push(st.size()-1) ; 
        }
    }
    
    void pop() {
        if(minst.top()==st.size()-1) minst.pop() ; 
        st.pop_back() ; 
    }
    
    int top() {
        return st[st.size()-1] ; 
    }
    
    int getMin() {
        return st[minst.top()] ; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */