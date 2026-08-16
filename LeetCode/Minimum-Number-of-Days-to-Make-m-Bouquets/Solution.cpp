1class Solution {
2    bool bs(vector<int>&bloomDay, int day, int m , int k){
3        // Keep in mind we have to take adjancent flowers
4        int flower = 0, bundle = 0;
5        for(int i = 0; i<bloomDay.size(); i++){
6            if(bloomDay[i] <= day){
7                flower++;
8
9                if(flower == k){
10                    bundle++;
11                    flower = 0;
12                }
13            }
14            else{
15                flower = 0;
16            }
17        }
18        return bundle >= m;
19    }
20public:
21    int minDays(vector<int>& bloomDay, int m, int k) {
22        int n = bloomDay.size();
23        if(m > n/k){return -1;}
24
25        int maxi = INT_MIN, mini = INT_MAX;
26        for(int i = 0; i<n; i++){
27            maxi = max(maxi, bloomDay[i]);
28            mini = min(mini, bloomDay[i]);
29        }
30        // all garden flowers should be bloom in maxi days
31        // Our Optimal Anser should lie between 1 to maxi days
32
33        // This is like binary Search on Answer
34        int start = mini, end = maxi, ans = 0;
35        while(start <= end){
36            int mid = start + (end - start) / 2;
37            if(bs(bloomDay, mid, m, k)){
38                ans = mid;
39                end = mid-1;
40            }
41            else{
42                start = mid + 1;
43            }
44        }
45    return ans;
46    }
47};