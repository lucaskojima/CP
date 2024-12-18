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

struct DSU {
	vector<int> pai, siz, sum;
	DSU(int n) : pai(2 * n + 1), siz(2 * n + 1), sum(2 * n + 1) {
		for (int i = 1, j = n + 1; i <= n; i++, j++) {
			pai[i] = j;
			pai[j] = j;
			siz[j] = 1;
			sum[j] = i;
		}
	}
	int find(int v) { return pai[v] == v ? v : pai[v] = find(pai[v]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (siz[a] > siz[b]) swap(a, b);
		pai[a] = b;
		siz[b] += siz[a];
		sum[b] += sum[a];
	}
	void move(int a, int b) {
		int repA = find(a), repB = find(b);
		if (repA == repB) return;
		siz[repA]--, sum[repA] -= a;
		siz[repB]++, sum[repB] += a;
		pai[a] = repB;
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m; while (cin >> n >> m) {
		DSU dsu(n);
		while (m--) {
			int op; cin >> op;
			if (op == 1) {
				int p, q; cin >> p >> q;
				dsu.join(p, q);
			}
			if (op == 2) {
				int p, q; cin >> p >> q;
				dsu.move(p, q);
			}
			if (op == 3) {
				int p; cin >> p;
				int rep = dsu.find(p);
				cout << dsu.siz[rep] << ' ' << dsu.sum[rep] << nl;
			}
		}
	}
	return 0;
}
