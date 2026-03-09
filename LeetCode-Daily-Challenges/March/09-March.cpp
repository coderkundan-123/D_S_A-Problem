class Solution {
public:
    //Bottom Up apporch hai 
    int M = 1e9 + 7;
    int t[201][201][2];
    //T.C : O(one * zero * limit);
    //s.c :  O(one * zero );

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, 0, sizeof(t));

        t[0][0][1] = 1;
        t[0][0][0] = 1;

        for(int oneleft = 0; oneleft <= one; oneleft++){
            for(int zeroleft = 0; zeroleft <= zero; zeroleft++){

                if(oneleft == 0 && zeroleft == 0) continue;

                int ans = 0;

                for(int len = 1; len <= min(zeroleft, limit); len++){
                    ans = (ans + t[oneleft][zeroleft - len][0])%M;
                }

                t[oneleft][zeroleft][1] = ans;

                ans = 0;

                for(int len = 1; len <= min(oneleft, limit); len++){
                    ans = (ans + t[oneleft-len][zeroleft][1])%M;
                }

                t[oneleft][zeroleft][0] = ans;
            }
        }

        int startWithOne = t[one][zero][false];
        int startWithZero = t[one][zero][true];
        return (startWithOne + startWithZero) % M;
    }
};
/****************** sec Method ***********************/
class Solution {
public:
    //Recursion Methods
    int M = 1e9 + 7;
    int t[201][201][2];
    //T.C : O(one * zero * limit);
    //s.c :  O(one * zero );

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, 0, sizeof(t));

        t[0][0][1] = 1;
        t[0][0][0] = 1;

        for(int oneleft = 0; oneleft <= one; oneleft++){
            for(int zeroleft = 0; zeroleft <= zero; zeroleft++){

                if(oneleft == 0 && zeroleft == 0) continue;

                int ans = 0;

                for(int len = 1; len <= min(zeroleft, limit); len++){
                    ans = (ans + t[oneleft][zeroleft - len][0])%M;
                }

                t[oneleft][zeroleft][1] = ans;

                ans = 0;

                for(int len = 1; len <= min(oneleft, limit); len++){
                    ans = (ans + t[oneleft-len][zeroleft][1])%M;
                }

                t[oneleft][zeroleft][0] = ans;
            }
        }

        int startWithOne = t[one][zero][false];
        int startWithZero = t[one][zero][true];
        return (startWithOne + startWithZero) % M;
    }
};
