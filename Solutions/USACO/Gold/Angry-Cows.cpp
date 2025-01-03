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

void setIO(string s) {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main() {
	setIO("angry");

	int n; cin >> n;
	vector<int> v(n); for (auto &x : v) { cin >> x; x *= 2; }

	sort(all(v));

	auto checkL = [&](int p, int d) -> bool {
		int nxt = n - 1;
		while (p > v[0]) {
			while (nxt - 1 >= 0 && p - d <= v[nxt - 1]) nxt--;
			if (p == v[nxt]) return false;
			p = v[nxt];
			d -= 2;
		}
		return true;
	};

	auto checkR = [&](int p, int d) -> bool {
		int nxt = 0;
		while (p < v.back()) {
			while (nxt + 1 < n && v[nxt + 1] <= p + d) nxt++;
			if (p == v[nxt]) return false;
			p = v[nxt];
			d -= 2;
		}
		return true;
	};

	auto check = [&](int d) -> bool {
		int l = v[0] - 1; // F
		int r = v[n - 1]; // T
		while (r > l + 1) {
			int m = (l + r) / 2;
			checkR(m, d) ? r = m : l = m;
		}
		return checkL(r, d);
	};

	int l = -1;  // F
	int r = 2e9; // T
	while (r > l + 1) {
		int m = (l + r) / 2;
		check(m) ? r = m : l = m;
	}

	cout << fixed << setprecision(1) << (double) r / 2 << nl;
	return 0;
}
