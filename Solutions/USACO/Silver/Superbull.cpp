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

struct DSU {
	vector<int> pai, rank;
	DSU(int n) : pai(n + 1), rank(n + 1) {
		for (int i = 1; i <= n; i++) pai[i] = i;
	}

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

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main() {
	setIO("superbull");

	int n; cin >> n;
	vector<int> v(n); for (auto &x : v) cin >> x;

	vector<pair<int, pii>> edges;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			edges.push_back({v[i] ^ v[j], {i, j}});
		}
	}

	sort(rall(edges));

	DSU dsu(n);
	int ans = 0;

	for (int i = 0; i < sz(edges); i++) {
		auto [w, aux] = edges[i];
		auto [a, b] = aux;

		if (dsu.find(a) != dsu.find(b)) {
			dsu.une(a, b);
			ans += w;
		}
	}

	cout << ans << nl;
	return 0;
}
