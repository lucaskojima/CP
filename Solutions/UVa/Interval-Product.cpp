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

struct BIT {
	vector<int> bit; int n;
	BIT(int n) : bit(n + 1), n(n) {}

	void update(int i, int v) {
		for (; i <= n; i += (i & -i))
			bit[i] += v;
	}
	int query(int i) {
		int sum = 0;
		for (; i >= 1; i -= (i & -i))
			sum += bit[i];
		return sum;
	}
	int query(int l, int r) { return query(r) - query(l - 1); }
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, q; while (cin >> n >> q) {
		BIT neg(n), zero(n);

		for (int i = 1; i <= n; i++) {
			int v; cin >> v;
			if (v == 0)
				zero.update(i, 1);
			if (v < 0)
				neg.update(i, 1);
		}

		while (q--) {
			char op; cin >> op;
			if (op == 'C') {
				int i, v; cin >> i >> v;
				if (zero.query(i, i) == 1) zero.update(i, -1);
				if (neg.query(i, i) == 1) neg.update(i, -1);

				if (v == 0) zero.update(i, 1);
				if (v < 0) neg.update(i, 1);
			} else {
				int l, r; cin >> l >> r;
				if (zero.query(l, r) > 0)
					cout << '0';
				else if (neg.query(l, r) % 2 == 1)
					cout << '-';
				else
					cout << '+';
			}
		}
		cout << endl;
	}
	return 0;
}
