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
const int C   = 11;

template<typename T> void chmax(T &a, T b) { if (b > a) a = b; }

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;

  vector<int> p(n), d(n);
  vector<long long> e(n);

  for (int i = 1; i < n; i++) {
    cin >> p[i] >> d[i] >> e[i];
    p[i]--;
  }

  for (int i = 1; i < n; i++)
    e[i] += e[p[i]];

  vector<vector<int>> t(n);
  t[0] = vector<int>(C, -1);

  for (int i = 1; i < n; i++) {
    t[i] = t[p[i]];
    t[i].push_back(d[i]);
    sort(rall(t[i]));
    t[i].resize(C);
  }

  vector de(C, vector<pair<int, long long>>(n));
  for (int k = 0; k < C; k++) {
    for (int i = 0; i < n; i++)
      de[k][i] = {t[i][k], e[i]};
    sort(all(de[k]));
    for (int i = 1; i < n; i++)
      chmax(de[k][i].second, de[k][i - 1].second);
  }

  int m; cin >> m;
  while (m--) {
    int s, c; cin >> s >> c;

    int p = upper_bound(all(de[c]), pair{s, LINF}) - de[c].begin();
    cout << de[c][p - 1].second << nl;
  }
  return 0;
}
