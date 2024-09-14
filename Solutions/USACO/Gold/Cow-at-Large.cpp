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
	setIO("atlarge");

	int n, k; cin >> n >> k;

	vector<vector<int>> adj(n + 1);
	vector<int> deg(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		deg[a]++; deg[b]++;
	}

	vector<vector<int>> dist(n + 1, vector<int>(2, INF));
	
	auto bfs = [&](int t) -> void {
		queue<int> q;
		if (t == 0) { dist[k][t] = 0; q.push(k); }
		else {
			for (int i = 1; i <= n; i++) 
				if (deg[i] == 1) {
					dist[i][t] = 0;
					q.push(i);
				}
		}

		while (!q.empty()) {
			int x = q.front(); q.pop();

			for (auto k : adj[x]) {
				if (dist[k][t] == INF) {
					dist[k][t] = dist[x][t] + 1;
					q.push(k);
				}
			}
		}
	};

	bfs(0);
	bfs(1);

	vector<int> vis(n + 1);
	queue<int> q;

	vis[k] = 1;
	q.push(k);

	int ans = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (dist[x][1] <= dist[x][0]) { ans++; continue; }

		for (auto k : adj[x]) {
			if (vis[k] == 0) {
				vis[k] = 1;
				q.push(k);
			}
		}
	}

	cout << ans << nl;
	return 0;
}
