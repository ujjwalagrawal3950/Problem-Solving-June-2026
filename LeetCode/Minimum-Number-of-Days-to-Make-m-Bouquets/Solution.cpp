1class Solution {
2    bool isPossible(vector<int>&bloomDay , int m , int k , int mid){
3        int flower = 0 , bundle = 0;
4        for(int i = 0; i<bloomDay.size(); i++){
5            if(bloomDay[i] <= mid){
6                flower++;
7                if(flower == k){
8                    bundle++;
9                    flower = 0;
10                }
11            }
12            else{
13                flower = 0;
14            }
15        }
16        if(bundle < m){
17            return false;
18        }
19        
20        return true;
21    }
22public:
23    int minDays(vector<int>& bloomDay, int m, int k) {
24        int start = INT_MAX;
25        int end = INT_MIN;
26        int ans = -1;
27        for(int i = 0; i<bloomDay.size(); i++){
28            start = min(start , bloomDay[i]);
29            end   = max(end   , bloomDay[i]);
30        }
31
32        while(start <= end){
33            int mid = start + (end - start)/2;
34            if(isPossible(bloomDay , m , k , mid)){
35                ans = mid;
36                end = mid-1;
37            }
38            else{
39                start = mid+1;
40            }
41        }
42        return ans;
43    }
44};