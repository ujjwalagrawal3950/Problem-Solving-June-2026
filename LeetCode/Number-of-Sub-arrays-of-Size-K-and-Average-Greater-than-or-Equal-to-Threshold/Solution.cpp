1class Solution {
2public:
3    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
4        int start = 0, count = 0, sum   = 0;
5        for(int i = 0; i<arr.size(); i++){
6            sum += arr[i];
7            if(i >= k-1){
8                // calculate things here
9                int avg = sum / k;
10                if(avg >= threshold){count++;}
11                sum -= arr[start++];
12            }
13        }
14        return count;
15    }
16};