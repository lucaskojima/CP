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

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n; cin >> n;

	vector<vector<int>> adj(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int ans = 0;

	auto dfs = [&](auto dfs, int x, int p) -> void {
		int son = (x == 1 ? sz(adj[x]) + 1 :  sz(adj[x]));
		int cnt = 1;
		while (cnt < son) { ans++, cnt *= 2; }

		for (auto k : adj[x]) {
			if (k == p) continue;
			dfs(dfs, k, x);
			ans++;
		}
	};
	dfs(dfs, 1, -1);

	cout << ans << nl;
	return 0;
}
