1class Solution {
2public:
3    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
4        int k = 0;
5       for(int i = m; i<nums1.size(); i++){
6        nums1[i] = nums2[k];
7        k++;
8       }
9       sort(nums1.begin() , nums1.end());
10    }
11};