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

int main() {
	setIO("mootube");

	int n, q; cin >> n >> q;

	vector<vector<pii>> adj(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	for (int i = 0; i < q; i++) {
		int w, v; cin >> w >> v;

		vector<int> vis(n + 1);
		int ans = 0;

		auto dfs = [&](auto dfs, int x) -> void {
			vis[x] = 1;
			ans++;
			for (auto [k, ww] : adj[x]) {
				if (vis[k] || ww < w) continue;
				dfs(dfs, k);
			}
		};

		dfs(dfs, v);

		cout << ans - 1 << nl;
	}
	return 0;
}
