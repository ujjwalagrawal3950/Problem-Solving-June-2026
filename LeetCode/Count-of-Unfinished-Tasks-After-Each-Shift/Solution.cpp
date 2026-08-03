1class Solution {
2public:
3    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
4        vector<long long>prefix;
5        vector<int>ans;
6        int n = tasks.size();
7        long long sum = 0; 
8
9        for(int x : tasks){ sum +=x; prefix.push_back(sum);}
10
11        long long total = prefix.back(), progress = 0;
12
13        for(int shift : shifts){
14            if(progress + shift >= total){
15                ans.push_back(0);
16                progress = 0;
17            }
18            else{
19                progress += shift;
20                int idx = upper_bound(prefix.begin(), prefix.end(), progress)-prefix.begin();
21                ans.push_back(n-idx);
22            }
23        }
24    return ans;
25    }
26};