/****************** Recursion Methods ************/
/* T.C :O(2^n)
   S.C :O(n)
*/
class Solution {
public:
    int solve(int n){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }

        int one_step = solve(n-1);
        int two_step = solve(n-2);

        return one_step + two_step;
    }
    int climbStairs(int n) {
        return solve(n);
    }
};
/**************************** memo **************/
/* T.C :O(n)
   S.C :O(n)
*/
class Solution {
public:
    int t[46];
    int solve(int n){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }

        if(t[n] != -1){
            return t[n];
        }

        int one_step = solve(n-1);
        int two_step = solve(n-2);

        return t[n] = one_step + two_step;
    }
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};
/************ Bottom-up ***************/
/* T.C :O(n)
   S.C :O(n)
*/
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2){
            return n;
        }
        vector<int> t(n+1);

        t[0] = 0;
        t[1] = 1;
        t[2] = 2;

        for(int i = 3; i<=n; i++){
            t[i] = t[i-1] + t[i-2];
        }

        return t[n];
    }
};
/************* 4th Methods ************/
/* T.C :O(n)
   S.C :O(1)
*/
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2){
            return n;
        }
        int a = 1; // i-2
        int b = 2;//  i-1
        int c = 3;// i;

        for(int i = 3; i<=n; i++){
            c = a+b;
            a = b;
            b = c;
        }

        return c;
    }
};
