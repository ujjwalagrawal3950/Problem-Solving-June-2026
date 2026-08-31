1class MinStack {
2    stack<int>st, minStack;
3public:
4    MinStack() {
5        
6    }
7    
8    void push(int value) {
9        if(minStack.empty()) minStack.push(value);
10        else minStack.push(min(value, minStack.top()));
11        st.push(value);
12    }
13    
14    void pop() {
15        st.pop(); minStack.pop();
16    }
17    
18    int top() {
19        return st.top();
20    }
21    
22    int getMin() {
23        return minStack.top();
24    }
25};
26
27/**
28 * Your MinStack object will be instantiated and called as such:
29 * MinStack* obj = new MinStack();
30 * obj->push(value);
31 * obj->pop();
32 * int param_3 = obj->top();
33 * int param_4 = obj->getMin();
34 */