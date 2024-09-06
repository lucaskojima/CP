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
	setIO("milkvisits");

	int n, q; cin >> n >> q;
	string s; cin >> s;	

	vector<int> val(n + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == 'H') val[i] = 0;
		else val[i] = 1;
	}

	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> vis(n + 1);
	for (int i = 1; i <= n; i++) {
		if (vis[i] != 0) continue;

		auto dfs = [&](auto dfs, int x) -> void {
			vis[x] = i;
			for (auto k : adj[x]) {
				if (vis[k] || val[k] != val[i]) continue;
				dfs(dfs, k);
			}
		}; dfs(dfs, i);
	}

	while (q--) {
		int a, b; char c; cin >> a >> b >> c;
		int k = (c == 'H' ? 0 : 1);

		if (val[a] != k && val[b] != k && vis[a] == vis[b])
			cout << 0;
		else
			cout << 1;
	}
	return 0;
}
