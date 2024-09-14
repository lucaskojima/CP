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
	setIO("art2");

	int n; cin >> n;

	vector<int> v(n);
	vector<int> ini(n + 1, INF), fim(n + 1, -INF);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		ini[v[i]] = min(ini[v[i]], i);
		fim[v[i]] = max(fim[v[i]], i);
	}

	stack<int> st;
	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		int val = v[i];
		if (val == 0) continue;

		if (ini[val] == i)
			st.push(val);

		ans = max(ans, sz(st));

		if (fim[val] == i)
			if (st.top() != val) { cout << -1 << nl; return 0; }
			else st.pop();
	}

	cout << ans << nl;
	return 0;
}
