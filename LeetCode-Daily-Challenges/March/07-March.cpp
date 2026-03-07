/*********** first Method *********************/
class Solution {
public:
    //T.C : O(n)
    //S.C : O(1)
    int minFlips(string s) {
        int n = s.length();
        int minans = INT_MAX;
        int flip1 = 0;
        int flip2 = 0;
        int i=  0;
        int j = 0;

        while(j < 2*n){
            char expactedCharS1 = (j%2) ? '1' : '0';
            char expactedCharS2 = (j%2) ? '0' : '1';
            if(s[j%n] != expactedCharS1){
                flip1++;
            }

            if(s[j%n] != expactedCharS2){
                flip2++;
            }

            if(j - i + 1 > n){

                char expactedCharS1 = (i%2) ? '1' : '0';
                char expactedCharS2 = (i%2) ? '0' : '1';

                if(s[i%n] != expactedCharS1){
                    flip1--;
                }

                if(s[i%n] != expactedCharS2){
                    flip2--;
                }

                i++;
            }

            if(j - i + 1 == n){
                minans = min({minans, flip1, flip2});
            }
            j++;
        }

        return minans;
    }
};

/******************** sec Method *****************/
class Solution {
public:
    //T.C : O(1);
    //S.C : O(2*n);
    int minFlips(string s) {
        int n = s.length();
        string s1,s2;
        //s1 = 010101010;
        //s2 = 1010101010;
        for(int i=0; i<2*n; i++){
            s1 += (i%2 ? '0' : '1');
            s2 += (i%2 ? '1' : '0');
        }

        int minans = INT_MAX;
        int flip1 = 0;
        int flip2 = 0;
        int i=  0;
        int j = 0;

        while(j < 2*n){
            if(s[j%n] != s1[j]){
                flip1++;
            }

            if(s[j%n] != s2[j]){
                flip2++;
            }

            if(j - i + 1 > n){
                if(s[i%n] != s1[i]){
                    flip1--;
                }

                if(s[i%n] != s2[i]){
                    flip2--;
                }

                i++;
            }

            if(j - i + 1 == n){
                minans = min({minans, flip1, flip2});
            }
            j++;
        }

        return minans;
    }
};

/*************** third Method *****************/
class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        s = (s+s);
        string s1,s2;
        //s1 = 010101010;
        //s2 = 1010101010;
        for(int i=0; i<2*n; i++){
            s1 += (i%2 ? '0' : '1');
            s2 += (i%2 ? '1' : '0');
        }

        int minans = INT_MAX;
        int flip1 = 0;
        int flip2 = 0;
        int i=  0;
        int j = 0;

        while(j < 2*n){
            if(s[j] != s1[j]){
                flip1++;
            }

            if(s[j] != s2[j]){
                flip2++;
            }

            if(j - i + 1 > n){
                if(s[i] != s1[i]){
                    flip1--;
                }

                if(s[i] != s2[i]){
                    flip2--;
                }

                i++;
            }

            if(j - i + 1 == n){
                minans = min({minans, flip1, flip2});
            }
            j++;
        }

        return minans;
    }
};
