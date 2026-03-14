/******************* Method 1 *******************
T.C : O(n^2)
S.C : O(1)
Using rotate() repeatedly
************************************************/

/*
rotate(begin(s), begin(s)+k, end(s))

Example:
s = "abcdef"

rotate(begin(s), begin(s)+2, end(s))

Result:
cdefab
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
            rotate(s.begin(), s.begin()+1, s.end());

            if(s == goal)
                return true;
        }

        return false;
    }
};


/******************* Method 2 *******************
T.C : O(n)
S.C : O(n)
Using String Concatenation
************************************************/

/*
String concatenate example:

s = "abcde"
goal = "cdeab"

s + s = "abcdeabcde"

Now we check if "cdeab" exists in "abcdeabcde"
*/

class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length() != goal.length()){
            return false;
        }

        if((s + s).find(goal) != string::npos){
            return true;
        }

        return false;
    }
};


/******************* GFG Problem *******************
Problem: Strings Rotations of Each Other
Same concept as Method 2
***************************************************/
