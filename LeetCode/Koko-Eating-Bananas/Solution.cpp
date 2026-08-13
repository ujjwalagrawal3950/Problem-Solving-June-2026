1class Solution {
2    long long solve(vector<int>&piles, int h, int k){
3        long long hr = 0;
4        for(int i = 0; i<piles.size(); i++){
5            if(piles[i] % k != 0){
6                hr += ((piles[i]/k) + 1);
7            }else{
8                hr += (piles[i]/k);
9            }
10        }
11        return hr;
12    }
13
14
15public:
16    int minEatingSpeed(vector<int>& piles, int h) {
17        // I have to find minimum value of k such that koko can eat all the bananas
18        // range of k = [1 to max(arr[i])]
19        int n = piles.size();
20        int maxi = INT_MIN;
21        for(int i = 0; i<n; i++){maxi = max(maxi, piles[i]);}
22
23        int ans = 0; long long start = 1, end = maxi;
24
25        while(start <= end){
26            int mid = start + (end-start)/2;
27            long long hr = solve(piles, h, mid);
28            if(hr > h){
29                start = mid+1;
30            }
31            else {
32                ans = mid;
33                end = mid-1;
34            }
35        }
36        return ans;
37    }
38};