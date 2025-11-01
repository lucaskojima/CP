#include "bits/stdc++.h"
#define sz(x) (int)size(x)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root
 	int v;
 	explicit operator int() const { return v; }
	mint():v(0) {}
	mint(ll _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
	mint& operator+=(mint o) {
		if ((v += o.v) >= MOD) v -= MOD;
		return *this; }
	mint& operator-=(mint o) {
		if ((v -= o.v) < 0) v += MOD;
		return *this; }
	mint& operator*=(mint o) {
		v = int((ll)v*o.v%MOD); return *this; }
	friend mint pow(mint a, ll p) { assert(p >= 0);
		return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
	friend mint inv(mint a) { assert(a.v != 0); return pow(a,MOD-2); }
	friend mint operator+(mint a, mint b) { return a += b; }
	friend mint operator-(mint a, mint b) { return a -= b; }
	friend mint operator*(mint a, mint b) { return a *= b; }
};
using mi = mint<(int)1e9+9, 5>;

int32_t main() {
  freopen("team.in", "r", stdin);
  freopen("team.out", "w", stdout);

  int N, M, K; cin >> N >> M >> K;

  vector<ll> a(N + 1), b(M + 1);
  for (int i = 1; i <= N; i++)
    cin >> a[i];
  for (int i = 1; i <= M; i++)
    cin >> b[i];

  sort(1 + all(a));
  sort(1 + all(b));

  vector dp(N + 1, vector(M + 1, vector<mi>(K + 1)));
  for (int i = 0; i <= N; i++)
    for (int j = 0; j <= M; j++)
      dp[i][j][0] = 1;

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      for (int k = 1; k <= K; k++) {
        dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k];
        if (a[i] > b[j])
          dp[i][j][k] += dp[i - 1][j - 1][k - 1];
      }

  cout << int(dp[N][M][K]) << nl;
  return 0;
}
