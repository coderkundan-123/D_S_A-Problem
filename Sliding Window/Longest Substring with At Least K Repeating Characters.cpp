class Solution {
public:
    // Approach: Divide & Conquer
    // Time Complexity:
    // Worst → O(n²)
    // Average → O(n log n)

    // Space Complexity:
    // O(n)
    int solve(string &s, int st, int end, int k){
        if(end - st < k) return 0;
        vector<int> frq(26,0);
        for(int i=st; i<end; i++){
            frq[s[i] - 'a']++;
        }

        for(int i=st; i<end; i++){
            if(frq[s[i] - 'a'] < k){
                int mid = i+1;

                    while(mid < end && frq[s[mid]-'a'] < k){
                    mid++;
                }
            

                return max(solve(s, st, i, k), solve(s, mid, end, k));
            }
        }

        return end - st;
    }
    int longestSubstring(string s, int k) {
        int n = s.length();

        return solve(s, 0, n, k);
    }
};
