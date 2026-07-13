1class Solution {
2public:
3    bool isUgly(int n) {
4        
5        if(n == 0){return false;}
6        while(n%2 == 0 || n%3 == 0|| n%5 == 0){
7            if(n %2 ==  0){n /= 2;}
8            else if(n % 3 == 0){n /= 3;}
9            else if(n %5 == 0){n /= 5;}
10        }
11        return (n == 1) ? true: false;
12    }
13};