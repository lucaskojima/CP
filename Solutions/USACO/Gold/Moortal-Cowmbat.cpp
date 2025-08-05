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

template<typename T>
void chmin(T &a, T b) { if (b < a) a = b; }

void setIO(string s) {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main() {
  setIO("cowmbat");

  int n, m, k; cin >> n >> m >> k;
  string s; cin >> s;

  vector d(m + 1, vector<int>(m + 1));
  for (int i = 1; i <= m; i++)
    for (int j= 1; j <= m; j++)
      cin >> d[i][j];

  for (int k = 1; k <= m; k++)
    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= m; j++)
        chmin(d[i][j], d[i][k] + d[k][j]);

  vector cst(n + 1, vector<int>(m + 1));
  vector pref(n + 1, vector<int>(m + 1));

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cst[i][j] = d[s[i - 1] - 'a' + 1][j];
      pref[i][j] = pref[i - 1][j] + cst[i][j];
    }

  vector dp(n + 1, vector<int>(m + 1, INF));
  vector<int> mindp(n + 1, INF);
  mindp[0] = 0;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      chmin(dp[i][j], dp[i - 1][j] + cst[i][j]);
      if (i - k >= 0)
        chmin(dp[i][j], pref[i][j] - pref[i - k][j] + mindp[i - k]);

      chmin(mindp[i], dp[i][j]);
    }

  cout << mindp[n] << nl;
  return 0;
}
