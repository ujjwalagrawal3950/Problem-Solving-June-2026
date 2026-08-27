1class Solution {
2public:
3    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
4        vector<int> ans(m + n);
5        int i = 0, j = 0, k = 0;
6        while (i < m && j < n) {
7            if (nums1[i] < nums2[j]) {
8                ans[k++] = nums1[i++];
9            } else {
10                ans[k++] = nums2[j++];
11            }
12        }
13        while (i < m) {
14            ans[k++] = nums1[i++];
15        }
16        while (j < n) {
17            ans[k++] = nums2[j++];
18        }
19        for (int i = 0; i < m + n; i++) {
20            nums1[i] = ans[i];
21        }
22    }
23};
24