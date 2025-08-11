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

void setIO(string s) {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main() {
  setIO("sabotage");

  int n; cin >> n;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  auto val = [&](double k) -> bool {
    vector<double> b(n + 1);
    for (int i = 1; i <= n; i++)
      b[i] = (double) a[i] - k;

    double cur = b[2];
    double bst = b[2];
    for (int i = 3; i <= n - 1; i++) {
      if (cur < 0) cur = 0;
      cur += b[i];
      if (cur > bst) bst = cur;
    }

    double l = (double) accumulate(all(a), 0) - n * k;
    return bst >= l;
  };

  double l = 0;
  double r = 1e8;
  for (int i = 0; i < 100; i++) {
    double m = (l + r) / 2;
    val(m) ? r = m : l = m;
  }

  cout << fixed << setprecision(3) << r << nl;
  return 0;
}
