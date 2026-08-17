// T.C = O(n * Sum)
// S.C = O(n * Sum)

/************************************** Problem Number 01 ******************/
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();

        vector<vector<bool>> t(n + 1, vector<bool>(sum + 1, false));

        // Sum = 0 possible hai: empty subset
        for (int i = 0; i <= n; i++) {
            t[i][0] = true;
        }

        // 0 elements se positive sum possible nahi
        for (int j = 1; j <= sum; j++) {
            t[0][j] = false;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {

                if (arr[i - 1] <= j) {
                    t[i][j] =
                        t[i - 1][j - arr[i - 1]] ||
                        t[i - 1][j];
                }
                else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][sum];
    }
};
