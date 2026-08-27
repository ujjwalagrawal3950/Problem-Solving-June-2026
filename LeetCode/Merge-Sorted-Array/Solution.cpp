1class Solution {
2public:
3    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
4        int i  = m-1 , j  = n-1;
5        int idx = m + n - 1;
6
7        while(i >= 0 && j >= 0){
8            if(nums1[i] >= nums2[j]){
9                nums1[idx] = nums1[i--];
10            }
11            else{
12                nums1[idx]=  nums2[j--];
13            }
14            idx--;
15        }
16        while(j >= 0){
17            nums1[idx--] = nums2[j--];
18        }
19    }
20};