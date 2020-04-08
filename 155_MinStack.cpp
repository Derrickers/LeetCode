class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> mins;
    int min;
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int x) {
        s.push(x);
        if(x<=min){
            mins.push(x);
            min = x;
        }
    }
    
    void pop() {
        if(s.top() == min){
            mins.pop();
            min =mins.empty()?INT_MAX:mins.top();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */