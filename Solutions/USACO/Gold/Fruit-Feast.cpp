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
	setIO("feast");

	int t, a, b; cin >> t >> a >> b;

	vector<vector<int>> dp(t + 1, vector<int>(2));
	dp[0][0] = true;

	for (int i = 0; i <= t; i++) {
		if (i - a >= 0) dp[i][0] |= dp[i - a][0];
		if (i - b >= 0) dp[i][0] |= dp[i - b][0];
		dp[i / 2][1] |= dp[i][0];
	}

	for (int i = 0; i <= t; i++) {
		if (i - a >= 0) dp[i][1] |= dp[i - a][1];
		if (i - b >= 0) dp[i][1] |= dp[i - b][1];
	}

	for (int i = t; i >= 0; i--) {
		if (dp[i][0] || dp[i][1]) {
			cout << i << nl;
			return 0;
		}
	}
	return 0;
}
