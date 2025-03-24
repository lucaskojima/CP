#include "bits/stdc++.h"
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const char nl = '\n';
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

void setIO(string s) {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

void solve() {
  int n, q; cin >> n >> q;
  vector<int> a(n); for (auto &x : a) cin >> x;

  sort(all(a));

  while (q--) {
    int l, r; cin >> l >> r;
    cout << upper_bound(all(a), r) - lower_bound(all(a), l) << nl;
  }
}

int32_t main() {
  setIO("haybales");

  int T = 1;
  while (T--)
    solve();

  return 0;
}

