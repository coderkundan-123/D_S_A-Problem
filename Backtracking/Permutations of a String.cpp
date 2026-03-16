/************* cpp solution **************/
/* T.C :O(n * n!)
   S.C :O(n)
*/
class Solution { // GFG PROBLEM 
  public:
    void solve(int i, int n, string &s, string &prem, unordered_set<string>&st){
        if(prem.size() == n){
            st.insert(prem);
            return;
        }
        for(int j=i; j<n; j++){
            swap(s[i], s[j]);
            prem.push_back(s[i]);
            solve(i+1, n, s, prem, st);
            prem.pop_back();
            swap(s[i], s[j]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        unordered_set<string> st;
        int n = s.size();
        string prem;
        solve(0,n,s,prem,st);
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};

