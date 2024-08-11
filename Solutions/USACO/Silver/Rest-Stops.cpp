#include "bits/stdc++.h"
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long

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

int32_t main() {
	setIO("reststops");

	int l, n, rf, rb; cin >> l >> n >> rf >> rb;

	vector<pii> v;
	for (int i = 0; i < n; i++) {
		int x, c; cin >> x >> c;
		while (!v.empty() && v.back().ss < c) {
			v.pop_back();
		}
		v.push_back({x, c});
	}

	int ans = 0, prev = 0;
	for (int i = 0; i < sz(v); i++) {
		int dist = v[i].ff - prev;
		ans += ((dist * rf) - (dist * rb)) * v[i].ss;
		prev = v[i].ff;
	}

	cout << ans << nl;
	return 0;
}
