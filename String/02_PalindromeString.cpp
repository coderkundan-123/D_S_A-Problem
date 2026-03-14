/* T.C : O(n)
  S.C  : O(1)
*/
class Solution {
  public:
    bool AlphNum(char ch){
        if((ch >= '0' && ch <= '9') ||
          (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
            return true;
        }
        
        return false;
    }
    bool isPalindrome(string& s) {
        // code here
        int st = 0, end = s.length()-1;
        while(st < end){
            if(!AlphNum(s[st])){
               st++; 
               continue;
            }
            
            if(!AlphNum(s[end])){
               end--; 
               continue;
            }
            if(tolower(s[st]) != tolower(s[end])){
               return false;
            }
            
            st++;
            end--;
        }
        
        return true;
        
    }
};

/************** leedcode 125 ***************/
/* T.C : O(n)
  S.C  : O(1)
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, end = s.size()-1;
        while(st < end){
            if(!isalnum(s[st])){st++; continue;}
            if(!isalnum(s[end])) {end--; continue;}

            if(tolower(s[st]) != tolower(s[end])){
                return false;
            }

            st++;
            end--;
        }
        return true;
    }
};
