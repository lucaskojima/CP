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

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main(){
	setIO("nocross");

    int n; cin >> n;
    vector<int> a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> b(n + 1); for (int i = 1; i <= n; i++) cin >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    dp[1][1] = abs(a[1] - b[1]) <= 4 ? 1 : 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int add = abs(a[i] - b[j]) <= 4 ? dp[i - 1][j - 1] + 1 : 0;
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], add});
        }
    }

    cout << dp[n][n] << nl;
	return 0;
}
