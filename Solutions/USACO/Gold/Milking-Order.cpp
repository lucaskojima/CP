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
	setIO("milkorder");

	int n, m; cin >> n >> m;

	vector<vector<int>> obs(m + 1);

	for (int i = 1; i <= m; i++) {
		int q; cin >> q;
		while (q--) {
			int v; cin >> v;
			obs[i].push_back(v);
		}
	}

	vector<vector<int>> adj(n + 1);
	vector<int> ing(n + 1), ans(n);
	iota(all(ans), 1);

	auto ok = [&](int pos) -> bool {
		for (int i = 1; i <= n; i++) adj[i].clear();
		fill(all(ing), 0);

		for (int i = 1; i <= pos; i++) {
			for (int j = 0; j < sz(obs[i]) - 1; j++) {
				int a = obs[i][j], b = obs[i][j + 1];
				adj[a].push_back(b);
				ing[b]++;
			}
		}

		priority_queue<int, vector<int>, greater<int>> q;
		for (int i = 1; i <= n; i++)
			if (ing[i] == 0) q.push(i);

		vector<int> top;
		while (!q.empty()) {
			int x = q.top(); q.pop();
			top.push_back(x);

			for (auto k : adj[x]) {
				if (--ing[k] == 0) q.push(k);
			}
		}

		if (sz(top) == n) for (int i = 0; i < n; i++) ans[i] = top[i];
		return sz(top) == n;
	};

	int l = 0;     // l is good
	int r = m + 1; // r is bad
	while (r > l + 1) {
		int m = (l + r) / 2;
		ok(m) ? l = m : r = m;
	}

	for (int i = 0; i < n; i++) {
		if (i != 0) cout << ' ';
		cout << ans[i];
	}
	return 0;
}
