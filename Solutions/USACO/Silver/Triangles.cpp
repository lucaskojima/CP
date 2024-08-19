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
const int MOD = 1e9 + 7;

void setIO(string s) {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main() {
	setIO("triangles");

	int n; cin >> n;

	map<int, vector<pii>> px, py;

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		py[y].push_back({x, i});
		px[x].push_back({y, i});
	}

	map<int, int> dx, dy;

	for (auto [y, v] : py) {
		sort(all(v));

		int dif = 0;
		for (int i = 1; i < sz(v); i++) {
			dif += v[i].ff - v[0].ff;
		}
		dx[v[0].ss] = dif % MOD;

		for (int i = 1; i < sz(v); i++) {
			dif = dif + (v[i].ff - v[i - 1].ff) * (2 * i - sz(v));
			dx[v[i].ss] = dif % MOD;
		}
	}

	for (auto [x, v] : px) {
		sort(all(v));

		int dif = 0;
		for (int i = 1; i < sz(v); i++) {
			dif += v[i].ff - v[0].ff;
		}
		dy[v[0].ss] = dif % MOD;

		for (int i = 1; i < sz(v); i++) {
			dif = dif + (v[i].ff - v[i - 1].ff) * (2 * i - sz(v));
			dy[v[i].ss] = dif % MOD;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int add = (dx[i] * dy[i]) % MOD;
		ans = (ans + add) % MOD;
	}

	cout << ans << nl;
	return 0;
}
