1class Solution {
2public:
3    void nextPermutation(vector<int>& arr) {
4        int n = arr.size();
5        int index  = -1;
6        for (int i = n - 2; i >= 0; i--) {
7            if (arr[i] < arr[i + 1]) {
8                index = i;
9                break;
10            }
11        }
12        // cout<<"Index  "<<index<<endl;
13        if(index == -1){
14            return reverse(arr.begin() , arr.end());
15        }
16       //  2 | 1 5 4 3 0 0  example and we stop after two due to dip 
17       for(int i = n-1 ; i>index ; i--){
18            if(arr[i] > arr[index]){
19                swap(arr[i] , arr[index]);
20                break;
21            }
22       }
23       return reverse(arr.begin()+index+1 , arr.end());
24    }
25};