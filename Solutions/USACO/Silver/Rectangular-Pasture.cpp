#include "bits/stdc++.h"
#define sz(x) (int)size(x)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

struct T {
  int x, y;
};

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;
  vector<T> a(n);
  for (auto &[x, y] : a)
    cin >> x >> y;

  sort(all(a), [](const T &a, const T &b){
    return a.x < b.x;
  });
  for (int i = 0; i < n; i++)
    a[i].x = i + 1;

  sort(all(a), [](const T &a, const T &b){
    return a.y < b.y;
  });
  for (int i = 0; i< n; i++)
    a[i].y = i + 1;

  vector p(n + 1, vector<int>(n + 1));
  for (int i = 0; i < n; i++)
    p[a[i].x][a[i].y] = 1;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];

  auto calc = [&](int l, int c, int ll, int cc) -> int {
    return p[ll][cc] - p[ll][c - 1] - p[l - 1][cc] + p[l - 1][c - 1];
  };

  long long ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++) {
      int l = min(a[i].x, a[j].x);
      int c = min(a[i].y, a[j].y);
      int ll = max(a[i].x, a[j].x);
      int cc = max(a[i].y, a[j].y);

      int cntL = calc(l, 1, ll, c - 1);
      int cntR = calc(l, cc + 1, ll, n);
      ans += (cntL + 1) * (cntR + 1);
    }

  cout << ans + 1 << nl;
  return 0;
}

