#include "bits/stdc++.h"

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("fencedin.in","r",stdin);
  freopen("fencedin.out","w",stdout);

  int A, B, n, m; cin >> A >> B >> n >> m;

  vector<int> a(n), b(m);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  a.push_back(A);
  b.push_back(B);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  for (int i = n; i > 0; i--)
    a[i] = a[i] - a[i - 1];
  for (int i = m; i > 0; i--)
    b[i] = b[i] - b[i - 1];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  long long ans = 1LL * m * a[0] + 1LL * n * b[0];
  for (int i = 1, j = 1; i < n + 1 && j < m + 1; )
    if (a[i] < b[j])
      ans += 1LL * a[i++] * (m - j + 1);
    else
      ans += 1LL * b[j++] * (n - i + 1);

  cout << ans << '\n';
  return 0;
}
