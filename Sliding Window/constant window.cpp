/* T.C : O(N)
   S.C : O(1) */
/* Maximum Sum Subarray of Size K
  Fixed Size Window Maximum Sum
  Sliding Window Maximum Sum (K size)
  (LeetCode style) Maximum Sum Subarray of Size K */


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> arr = {-1, 2, 3, 4, 5, -1};
    int k = 4;
    int n = arr.size();

    int l = 0, r = k - 1;
    int sum = 0;

    // first window sum
    for (int i = 0; i <= r; i++) {
        sum += arr[i];
    }

    int maxSum = sum;

    // sliding window
    while (r < n - 1) {
        sum = sum - arr[l];  // remove left
        l++;
        r++;
        sum = sum + arr[r];  // add right

        maxSum = max(maxSum, sum);
    }

    cout << "Max Sum = " << maxSum;

    return 0;
}
