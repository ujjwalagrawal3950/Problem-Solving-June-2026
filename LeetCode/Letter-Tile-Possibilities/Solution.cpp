1class Solution {
2    int solution(string tiles, int idx, vector<bool>&visited){
3        if(idx >= tiles.length()){
4            return 1;
5        }
6
7        int result = 0;
8
9        for(int i = 0; i<tiles.length(); i++){
10
11            // This will handle duplication
12            if(i > 0 && tiles[i] == tiles[i-1] && !visited[i-1]) continue;
13
14            if(!visited[i]){
15                visited[i] = true;
16                result += solution(tiles, idx + 1, visited);
17                visited[i] = false;
18            }
19        }
20        return result + 1;
21    }
22public:
23    int numTilePossibilities(string tiles) {
24
25        int n = tiles.length();
26        vector<bool>visited(n, false); 
27        
28        sort(tiles.begin(), tiles.end());
29        // Har ek character k liye we have to check wheather is it visited or not
30        return solution(tiles, 0, visited) - 1;
31    }
32};