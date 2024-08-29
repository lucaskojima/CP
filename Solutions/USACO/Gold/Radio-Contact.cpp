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
	setIO("radio");

	int n, m; cin >> n >> m;

	vector<pii> fj(n + 1); cin >> fj[0].ff >> fj[0].ss;
	vector<pii> vb(m + 1); cin >> vb[0].ff >> vb[0].ss;

	string a, b; cin >> a >> b;

	for (int i = 1; i <= n; i++) {
		fj[i].ff = fj[i - 1].ff;
		fj[i].ss = fj[i - 1].ss;

		if (a[i - 1] == 'E') fj[i].ff++;
		if (a[i - 1] == 'W') fj[i].ff--;
		if (a[i - 1] == 'N') fj[i].ss++;
		if (a[i - 1] == 'S') fj[i].ss--;
	}

	for (int i = 1; i <= m; i++) {
		vb[i].ff = vb[i - 1].ff;
		vb[i].ss = vb[i - 1].ss;

		if (b[i - 1] == 'E') vb[i].ff++;
		if (b[i - 1] == 'W') vb[i].ff--;
		if (b[i - 1] == 'N') vb[i].ss++;
		if (b[i - 1] == 'S') vb[i].ss--;
	}

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
	dp[0][0] = 0;

	auto sqr = [](int a) -> int {
		return a * a;
	};

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 && j == 0) continue;

			if (i != 0) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			if (j != 0) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			if (i != 0 && j != 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
			dp[i][j] += sqr((fj[i].ff - vb[j].ff)) + sqr((fj[i].ss - vb[j].ss));
		}
	}

	cout << dp[n][m] << nl;
	return 0;
}
