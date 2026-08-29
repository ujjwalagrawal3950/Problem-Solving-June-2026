1class Solution {
2public:
3    vector<int> asteroidCollision(vector<int>& asteroids) {
4        vector<int>ans;
5        stack<int>st;
6        for(int i = 0; i<asteroids.size(); i++){
7            if(asteroids[i] < 0){
8                while(!st.empty() && st.top() < abs(asteroids[i])){
9                    st.pop();
10                }
11                if(st.empty()){
12                   ans.push_back(asteroids[i]);
13                }
14                if(!st.empty() && (st.top() == abs(asteroids[i]))){
15                    st.pop();
16                }
17            }
18            else{
19                st.push(asteroids[i]);
20            }
21        }
22        int size = ans.size();
23        while(!st.empty()){
24            ans.push_back(st.top());
25            st.pop();
26        }
27        reverse(ans.begin()+size, ans.end());
28        return ans;
29    }
30};