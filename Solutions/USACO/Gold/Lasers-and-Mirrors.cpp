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
	setIO("lasers");

	int n; cin >> n;

	vector<pii> p(n + 2);
	map<int, vector<int>> x, y;

	for (int i = 0; i < n + 2; i++) {
		cin >> p[i].ff >> p[i].ss;
		x[p[i].ff].push_back(i);
		y[p[i].ss].push_back(i);
	}

	vector<int> dist(n + 2, INF);
	queue<pii> q;

	dist[0] = 0;
	q.push({0, 0}); q.push({0, 1});
	// 0 -> vem da horizontal
	// 1 -> vem da vertical

	while (!q.empty()) {
		auto [v, d] = q.front(); q.pop();

		for (auto k : (d == 0 ? x[p[v].ff] : y[p[v].ss])) {
			if (dist[k] != INF) continue;
			q.push({k, 1 - d});
			dist[k] = dist[v] + 1;
		}
	}

	cout << (dist[1] == INF ? -1 : dist[1] - 1) << nl;
	return 0;
}
