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
	setIO("fortmoo");

	int n, m; cin >> n >> m;

	vector<vector<int>> pref(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char c; cin >> c;
			int val = (c == 'X');
			pref[i][j] = val + pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1];
		}

	auto sum = [&](int l, int ll, int c, int cc) -> int {
		return pref[ll][cc] - pref[ll][c - 1] - pref[l - 1][cc] + pref[l - 1][c - 1];
	};

	int ans = 0;

	for (int l = 1; l <= n; l++)
		for (int ll = l; ll <= n; ll++)
			for (int c = 1, cc = 1; cc <= m; cc++) {
				if (sum(l, ll, cc, cc) > 0) continue;
				while (sum(l, l, c, cc) > 0 || sum(ll, ll, c, cc) > 0 || sum(l, ll, c, c) > 0) c++;
				ans = max(ans, (ll - l + 1) * (cc - c + 1));
			}

	cout << ans << nl;
	return 0;
}
