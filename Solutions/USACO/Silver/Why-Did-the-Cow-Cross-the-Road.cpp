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
	setIO("helpcross");

	int n, m; cin >> n >> m;
	vector<int> p(n); for (auto &x : p) cin >> x;
	vector<pii> r(m); for (auto &[x, y] : r) cin >> x >> y;

	sort(all(p));
	sort(all(r));

	multiset<int> st;
	int ans = 0;

	for (int i = 0, pos = 0; i < n; i++) {
		while (r[pos].ff <= p[i] && pos < m) {
			if (p[i] <= r[pos].ss) st.insert(r[pos].ss);
			pos++;
		}
		auto it = st.lower_bound(p[i]);
		if (it == st.end()) continue;
		st.erase(it);
		ans++;
	}

	cout << ans << nl;
	return 0;
}
