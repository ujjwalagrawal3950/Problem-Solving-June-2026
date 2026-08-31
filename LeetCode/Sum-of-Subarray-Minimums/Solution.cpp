1class Solution {
2    int n; // These are global variables
3    int mod = 1e9 + 7;
4
5    void NSE_On_Right(vector<int>&NextSmallerOnRight, vector<int>&arr){
6        stack<int>st;
7        for(int i = n-1; i>=0; i--){
8            while(!st.empty() && arr[st.top()] > arr[i]){
9                st.pop();
10            }
11            if(st.empty()) NextSmallerOnRight[i] = n-i;
12            else NextSmallerOnRight[i] = st.top() - i;
13            st.push(i);
14        }
15    }
16    void NSE_On_Left(vector<int>&NextSmallerOnLeft, vector<int>&arr){
17        stack<int>st;
18        for(int i = 0; i<n; i++){
19            while(!st.empty() && arr[st.top()] >= arr[i]){
20                st.pop();
21            }
22            if(st.empty()) NextSmallerOnLeft[i] = i + 1;
23            else NextSmallerOnLeft[i] = i - st.top();
24            st.push(i);
25        }
26    }
27public:
28    int sumSubarrayMins(vector<int>& arr) {
29        n = arr.size();
30        int ans = 0;
31        vector<int>NextSmallerOnRight(n), NextSmallerOnLeft(n);
32        NSE_On_Right(NextSmallerOnRight, arr);
33        NSE_On_Left(NextSmallerOnLeft,   arr);
34
35        for(int i = 0; i<n; i++){
36            ans = (ans + 1LL * arr[i] * NextSmallerOnRight[i] * NextSmallerOnLeft[i]) % mod;
37        }
38        return ans ;
39    }
40};