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

void setIO(string s) {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main() {
	setIO("bphoto");

	int n; cin >> n;

	vector<pii> val;
	for (int i = 1; i <= n; i++) {
		int v; cin >> v;
		val.push_back({v, i});
	}

	sort(rall(val));

	BIT bit(n);
	int ans = 0;

	for (int i = 0; i < n; i++) {
		auto [v, p] = val[i];
		int l = bit.query(1, p);
		int r = bit.query(p, n);
		ans += max(l, r) > 2 * min(l, r);
			
		bit.update(p, 1);
	}

	cout << ans << nl;
	return 0;
}
