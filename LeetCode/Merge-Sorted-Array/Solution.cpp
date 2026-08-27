1class Solution {
2public:
3    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
4        int k = nums1.size() - 1;
5        int i = m - 1;
6        int j = n - 1;
7        while (i >= 0 && j >= 0) {
8            if (nums1[i] < nums2[j]) {
9                nums1[k] = nums2[j];
10                j--;
11                k--;
12            } else {
13                nums1[k] = nums1[i];
14                k--;
15                i--;
16            }
17        }
18        while (j >= 0) {
19            nums1[k] = nums2[j];
20            k--;
21            j--;
22        }
23    }
24};