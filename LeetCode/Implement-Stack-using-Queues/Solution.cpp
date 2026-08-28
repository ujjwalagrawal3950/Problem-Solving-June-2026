1class MyStack {
2public:
3queue<int>q;
4    MyStack() {
5        
6    }
7    
8    void push(int x) {
9        q.push(x);
10        int n = q.size();
11        while(n != 1){
12            q.push(q.front());
13            q.pop();
14            n--;
15        }
16    }
17    
18    int pop() {
19        int elem = q.front(); q.pop();
20        return elem;
21    }
22    
23    int top() {
24        return q.front();
25    }
26    
27    bool empty() {
28        return q.empty();
29    }
30};
31
32/**
33 * Your MyStack object will be instantiated and called as such:
34 * MyStack* obj = new MyStack();
35 * obj->push(x);
36 * int param_2 = obj->pop();
37 * int param_3 = obj->top();
38 * bool param_4 = obj->empty();
39 */