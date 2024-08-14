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
	setIO("snakes");

	int n, k; cin >> n >> k;

	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];

	vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));

	int mX = 0, sum = 0, qnt = 0;
	for (int i = 1; i <= n; i++) {
		mX = max(mX, v[i]); sum += v[i]; qnt++;
		dp[i][0] = mX * qnt - sum;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			int mX = 0, sum = 0, qnt = 0;
			for (int k = i; k >= 1; k--) {
				dp[i][j] = min(dp[i][j], dp[k][j - 1] + (mX * qnt - sum));
				mX = max(mX, v[k]); sum += v[k]; qnt++;
			}
		}
	}

	cout << dp[n][k] << nl;
	return 0;
}
