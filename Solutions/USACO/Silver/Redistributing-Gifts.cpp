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

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n; cin >> n;

	vector<vector<int>> p(n + 1, vector<int>(n + 1));
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> p[i][j];

	vector<vector<int>> adj(n + 1);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int v = p[i][j];
			adj[i].push_back(v);
			if (i == v) break;
		}

	vector<vector<bool>> vis(n + 1, vector<bool>(n + 1));

	for (int i = 1; i <= n; i++) {
		auto dfs = [&](auto dfs, int x) -> void {
			vis[i][x] = true;
			for (auto k : adj[x]) {
				if (vis[i][k]) continue;
				dfs(dfs, k);
			}
		}; dfs(dfs, i);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int v = p[i][j];
			if (vis[i][v] && vis[v][i]) {
				cout << v << nl;
				break;
			}
		}
	return 0;
}
