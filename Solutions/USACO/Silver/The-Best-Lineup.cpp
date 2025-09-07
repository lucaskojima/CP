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

void solve() {
  int n; cin >> n;
  vector<int> a(n); for (auto &x : a) cin >> x;

  vector<pii> p;
  int max_suf = -INF;

  for (int i = n - 1; i >= 0; i--) {
    max_suf = max(max_suf, a[i]);
    if (a[i] == max_suf)
      p.push_back({i, a[i]});
  }

  reverse(all(p));
  p.insert(begin(p), {-1, -INF});
  p.push_back({n, -INF});

  for (int i = 1; i < sz(p) - 1; i++) {
    vector<pii> add;
    max_suf = p[i + 1].second;

    for (int j = p[i].first - 1; j > p[i - 1].first; j--) {
      max_suf = max(max_suf, a[j]);
      if (a[j] == max_suf)
        add.push_back({j, a[j]});
    }

    reverse(all(add));
    if (!add.empty()) {
      p.insert(begin(p) + i + 1, all(add));
      break;
    }
  }

  for (int i = 1; i < sz(p) - 1; i++) {
    cout << p[i].second;
    if (i != sz(p) - 2) cout << ' ';
  }
  cout << nl;
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int t; cin >> t;
  while (t--)
    solve();

  return 0;
}

