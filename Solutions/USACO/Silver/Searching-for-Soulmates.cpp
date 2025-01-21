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

void solve() {
	ll a, b; cin >> a >> b;

	auto rec = [&](auto rec, ll a, ll b) -> ll {
		if (a == b) return 0;
		else if (a > b)
			if (a & 1) return rec(rec, (a + 1) / 2, b) + 2;
			else       return rec(rec, a / 2, b) + 1;
		else
			if (b & 1) return min(rec(rec, a, (b - 1) / 2) + 2, b - a);
			else       return min(rec(rec, a, b / 2) + 1, b - a);
	};

	cout << rec(rec, a, b) << nl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int t; cin >> t;
	while (t--)
		solve();

	return 0;
}
