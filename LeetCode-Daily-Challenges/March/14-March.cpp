class Solution {
public:
    //T.C : 0(n * 3 * 2^n-1) hoga 
    //s.c = 0(n);
    void solve(int n, string curr, vector<string>& ans){
        if(curr.length() == n){
            ans.push_back(curr);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!curr.empty() && curr.back() == ch)
                continue;
            //DO
            curr.push_back(ch);
            //explore
            solve(n, curr, ans);
            //undo
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";

        vector<string> ans;
        solve(n, curr, ans);

        if(k > ans.size()){
            return "";
        }

        return ans[k-1];
    }
};

/************ sec Mechod **************/
class Solution {
public:
    //T.C : 0(n * 3 * 2^n-1) hoga 
    //s.c = 0(n);
    void solve(int n, string curr, int &count, int &k, string& ans){
        if(curr.length() == n){
            count++;
            if(count == k){
                ans = curr;
            }
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!curr.empty() && curr.back() == ch)
                continue;
            //DO
            curr.push_back(ch);
            //explore
            solve(n, curr, count, k, ans);
            //undo
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";

        string ans = "";
        int count = 0;
        solve(n, curr, count, k, ans);

        

        return ans;
    }
};
