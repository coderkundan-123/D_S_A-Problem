/* T.C :O(2^n)
   S.C :O(n)
*/
/* like example 
 n = 1 → "1"
 n = 2 → "11"      (one 1)
 n = 3 → "21"      (two 1s)
 n = 4 → "1211"    (one 2 one 1)
 n = 5 → "111221"
*/

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string say = countAndSay(n-1);
        string result="";
        for(int i=0; i<say.length(); i++){
            char ch = say[i];
            int count = 1;

            while(i < say.length()-1 && say[i] == say[i+1]){
                count++;
                i++;
            }
            result +=to_string(count) + string(1, ch);
        }

        return result;
    }
};
