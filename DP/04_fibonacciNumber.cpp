/********** Recursion Methods **************/
/* T.C :O(2^n)
   S.C :O(n)
*/
class Solution {
public:
    int solve(int n){
        if(n == 0 || n == 1){
            return n;
        }
        return fib(n-1) + fib(n-2);
    }
    int fib(int n) {
        return solve(n);
    }
};
/******************Memo ****************/
/* T.C : O(n)
   S.C :O(n)
*/
class Solution {
public:
    int t[31];
    int solve(int n){
        if(n == 0 || n == 1){
            return n;
        }
        if(t[n] != -1){
            return t[n];
        }
        return t[n] =  fib(n-1) + fib(n-2);
    }
    int fib(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};
/************ Bottom-up ***********/
/* T.C : O(n)
   S.C :O(n)
*/
class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1){
            return n;
        }

        vector<int> dp(n+1, -1);
        //dp[i] = ith fib number
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};
/************** 4th Methods ***********/
/* T.C : O(n)
   S.C :O(1)
*/
class Solution {
public:
    int fib(int n) {
        if(n == 0 || n == 1){
            return n;
        }
        int c;
        int a=0,b=1;
        
        for(int i=1; i<n; i++){
            c = a+b;
            a = b;
            b = c;
        }

        return c;
    }
};
