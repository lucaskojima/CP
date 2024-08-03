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

struct point {
	int id, x, y;
};

struct DSU {
	vector<int> pai, rank;
	DSU(int n) : pai(n), rank(n) { iota(all(pai), 0); }

	int find(int v) {
		return pai[v] == v ? v : pai[v] = find(pai[v]);
	}
	void une(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (rank[a] > rank[b]) swap(a, b);
		pai[a] = b;
		if (rank[a] == rank[b]) rank[b]++;
	}
};

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n; cin >> n;

	vector<point> v;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		v.push_back({i, x, y});
	}

	sort(all(v), [](point& a, point& b) {
		if (a.x != b.x) return a.x < b.x;
		return a.y < b.y;
	});

	vector<pair<int, pii>> edges;
	vector<point> marc(11, {-1, -1, -1});

	for (int i = 0; i < n; i++) {
		for (int y = 0; y <= 10; y++) {
			if (marc[y].id != -1) {
				point a = v[i], b = marc[y];
				int d = ((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y));
				edges.push_back({d, {a.id, b.id}});
			}
		}
		marc[v[i].y] = v[i]; 
	}

	sort(all(edges));

	DSU dsu(n);
	int ans = 0;

	for (int i = 0; i < sz(edges); i++) {
		auto [d, aux] = edges[i];
		auto [a, b] = aux;

		if (dsu.find(a) != dsu.find(b)) {
			dsu.une(a, b);
			ans += d;
		}
	}
	
	cout << ans << nl;
	return 0;
}
