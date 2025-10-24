/**
 * Description: calculates the longest increasing subsequence of an array
 * Source: https://cp-algorithms.com/dynamic_programming/longest_increasing_subsequence.html
 * Verification: https://cses.fi/problemset/result/15047849/
 * Time: O(N log N)
 */

int lis(vector<int> &a, int n) {
  vector<int> dp(n + 1, INF);
  dp[0] = -INF;
 
  for (int i = 0; i < n; i++) {
    int p = upper_bound(all(dp), a[i]) - dp.begin();
    if (dp[p - 1] < a[i] && a[i] < dp[p])
      dp[p] = a[i];
  }
 
  int ans = 0;
  for (int i = 0; i <= n; i++)
    if (dp[i] < INF)
      ans = i;
 
  return ans;
}
