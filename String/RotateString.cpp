/******************* cpp.solution ************/
/* T.C :O(n^2)
   S.C :O(1)
*/

 /* rotate(begin(s), begin(s)+k, end(s))

       Example:
       s = "abcdef"

       rotate(begin(s), begin(s)+2, end(s))

       Result:
       cdefab
       */
/* example abcdef ko convert abcfed to
   int main() {
    string s = "abcdef";

    reverse(s.begin()+3, s.end());

    cout << s;
}
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        if(m != n){
            return false;
        }

        for(int count = 1; count <= m; count++){
            rotate(begin(s), begin(s)+1, end(s));

            if(s == goal)
                return true;
        }

        return false;
    }
};

/*********** sec Methods **********/
/* T.C :O(n)
   S.c :O(n)
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        if(m != n){
            return false;
        }

      /* String concatenate example: 
        s = "abcde", goal = "cdeab". 
        We concatenate s + s = "abcdeabcde". 
        Now we check if "cdeab" exists in "abcdeabcde"
        */

        if((s+s).find(goal) != string::npos){ 
            return true;
        }

        return false;
    }
};

/*********** GFG problem *********/
/* Strings Rotations of Each Other
same concept per sec Method per submit hoga 
*/
