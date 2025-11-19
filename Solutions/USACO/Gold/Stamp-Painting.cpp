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

/**
 * Description: Modular arithmetic. Assumes $MOD$ is prime.
 * Source: KACTL
 * Verification: https://open.kattis.com/problems/modulararithmetic
 * Usage: mi a = MOD+5; inv(a); // 400000003
 */

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
using mi = mint<(int)1e9+7, 5>;

int32_t main() {
  freopen("spainting.in", "r", stdin);
  freopen("spainting.out", "w", stdout);

  int n, m, k; cin >> n >> m >> k;

  vector<mi> dp(n + 1), p(n + 1);
  dp[0] = p[0] = 1;

  for (int i = 1; i < k; i++) {
    dp[i] = dp[i - 1] * m;
    p[i] = p[i - 1] + dp[i];
  }

  for (int i = k; i <= n; i++) {
    dp[i] = (p[i - 1] - p[i - k]) * (m - 1);
    p[i] = p[i - 1] + dp[i];
  }

  mi val = 1;
  for (int i = 0; i < n; i++)
    val *= m;

  cout << int(val - dp[n]) << nl;
  return 0;
}
