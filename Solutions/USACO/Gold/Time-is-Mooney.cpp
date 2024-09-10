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
const int MAXT = 1000;

bool chmax(int &a, int b) { return b > a ? a = b, true : false; }

void setIO(string s) {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main() {
	setIO("time");

	int n, m, c; cin >> n >> m >> c;

	vector<int> w(n + 1);
	for (int i = 1; i <= n; i++) cin >> w[i];

	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}

	vector<vector<int>> dp(n + 1, vector<int>(MAXT, -INF));
	dp[1][0] = 0;

	for (int t = 0; t < MAXT - 1; t++)
		for (int x = 1; x <= n; x++) {
			if (dp[x][t] == -INF) continue;

			for (auto k : adj[x])
				chmax(dp[k][t + 1], dp[x][t] + w[k]);
		}

	int ans = 0;
	for (int t= 0; t < MAXT; t++)
		chmax(ans, dp[1][t] - (c * t * t));

	cout << ans << nl;
	return 0;
}
