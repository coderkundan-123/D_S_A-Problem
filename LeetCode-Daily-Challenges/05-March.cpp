/****************************** cpp solution *******************/
/* T.C : O(n) and S.C : O(1) */
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int start_with_0 = 0; // 0101010...so on
        int start_with_1 = 0; // 1010101...so on

        for(int i=0; i<n; i++){
            if(i%2 == 0){// even case
                if(s[i] == '0'){
                    start_with_1++;
                }else{
                    start_with_0++;
                }
            }else{ // odd case
                if(s[i] == '1'){
                    start_with_1++;
                }else{
                    start_with_0++;
                }
            }
        }

        return min(start_with_0, start_with_1);
    }
};

/************************* second Method ******************** /
/* T.C : O(n) and S.C : O(1) */
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int start_with_0 = 0; // 0101010...so on 

        for(int i=0; i<n; i++){
            if(i%2 == 0){// even case
                if(s[i] == '1'){
                    start_with_0++;
                }
            }else{ // odd case
                if(s[i] == '0'){
                    start_with_0++;
                }
            }
        }

        int start_with_1 = n - start_with_0;

        return min(start_with_0, start_with_1);
    }
};
