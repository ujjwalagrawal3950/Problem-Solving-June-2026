1class MyStack {
2private:
3    queue<int>q1, q2;
4public:
5    MyStack() {
6        
7    }
8    
9    void push(int x) {
10        q1.push(x);
11    }
12    
13    int pop() {
14        while(q1.size() != 1){
15            int elem = q1.front(); q1.pop();
16            q2.push(elem);
17        }
18        int pop_element = q1.front(); q1.pop();
19
20        while(!q2.empty()){
21            int elem = q2.front(); q2.pop();
22            q1.push(elem);
23        }
24        return pop_element;
25    }
26    
27    int top() {
28        while(q1.size() != 1){
29            int elem = q1.front(); q1.pop();
30            q2.push(elem);
31        }
32        int top_element = q1.front();
33        q2.push(top_element); q1.pop();
34
35        while(!q2.empty()){
36            int elem = q2.front(); q2.pop();
37            q1.push(elem);
38        }
39        return top_element;
40    }
41    
42    bool empty() {
43        return q1.empty();
44    }
45};
46
47/**
48 * Your MyStack object will be instantiated and called as such:
49 * MyStack* obj = new MyStack();
50 * obj->push(x);
51 * int param_2 = obj->pop();
52 * int param_3 = obj->top();
53 * bool param_4 = obj->empty();
54 */