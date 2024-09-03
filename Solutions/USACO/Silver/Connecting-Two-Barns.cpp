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

void solve() {
	int n, m; cin >> n >> m;
	
	vector<vector<int>> adj(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> vis(n + 1);

	auto dfs = [&](auto dfs, int x, vector<int> &ret) -> void {
		vis[x] = 1;
		ret.push_back(x);

		for (auto k : adj[x])
			if (!vis[k]) dfs(dfs, k, ret);
	};

	vector<int> c1; dfs(dfs, 1, c1);
	vector<int> cn; dfs(dfs, n, cn);

	sort(all(c1));
	sort(all(cn));

	for (auto x : c1)
		if (x == n) { cout << 0 << nl; return; }

	auto dist = [](int a, int b) -> int {
		return (a - b) * (a - b);
	};

	int ans = LINF;

	for (int i = 1; i < n; i++) {
		vector<int> comp;
		if (i == 1) comp = c1;
		else dfs(dfs, i, comp);

		int dist1 = LINF;
		int distn = LINF;

		for (auto x : comp) {
			auto it = lower_bound(all(c1), x);
			if (it != c1.end())
				dist1 = min(dist1, dist(*it, x));
			if (it != c1.begin()) {
				it--;
				dist1 = min(dist1, dist(*it, x));
			}

			it = lower_bound(all(cn), x);
			if (it != cn.end())
				distn = min(distn, dist(*it, x));
			if (it != cn.begin()) {
				it--;
				distn = min(distn, dist(*it, x));
			}
		}

		ans = min(ans, dist1 + distn);
	}

	cout << ans << nl;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}
