//T.C = O(n * totalSum)
//S.C = O(n * totalSum)

/***************************** Problem 04 ************************/
class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();

        int totalSum = 0;
        for (int x : arr) {
            totalSum += x;
        }

        vector<vector<bool>> dp(
            n + 1,
            vector<bool>(totalSum + 1, false)
        );

        // Sum 0 possible
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= totalSum; j++) {

                if (arr[i - 1] <= j) {
                    dp[i][j] =
                        dp[i - 1][j - arr[i - 1]] ||
                        dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        int ans = INT_MAX;

        // s1 <= totalSum / 2
        for (int s1 = 0; s1 <= totalSum / 2; s1++) {
            if (dp[n][s1]) {
                int s2 = totalSum - s1;
                ans = min(ans, abs(s2 - s1));
            }
        }

        return ans;
    }
};

