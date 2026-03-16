/*********** cpp ***********/
/* T.C : O(2^n)
   S.C :O(n * 2^n)
*/
class Solution {
  public:
    void RecAllpossible(string& s, int i, string prev, vector<string>& subsequance){
        if(i == s.size()){
            if(prev != "")// empty string 
                subsequance.push_back(prev);
            return;
        }
        //choose
        RecAllpossible(s, i+1, prev+s[i],subsequance);
        //reject
        RecAllpossible(s, i+1, prev,subsequance);
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string> subsequance;
        
        RecAllpossible(s, 0, "",subsequance);
        sort(subsequance.begin(), subsequance.end());
        return subsequance;
    }
};

/********** sec Method *********/
/* Bit - masking Apporch hai */
class Solution {
  public:
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string>total_sub;
        int n = s.size();
        for(int i=0; i<pow(2,n); i++){
            int curr = i;
            string temp = "";
            for(int i=0; i<=n; i++){
                if(curr & 1 << i){
                    temp +=s[i];
                }
            }
           // reverse(temp.begin(), temp.end());
            if(temp.size()){
                total_sub.push_back(temp);
            }
        }
        
        sort(total_sub.begin(), total_sub.end());
        return total_sub;
    }
};
