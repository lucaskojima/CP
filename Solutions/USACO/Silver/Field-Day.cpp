// https://usaco.org/current/data/sol_prob2_silver_open23.html
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

int to_bin(const string &s, int c) {
	int res = 0;
	for (int i = 0; i < c; i++)
		if (s[i] == 'H')
			res |= (1 << i);
	return res;
}

void chmin(int &a, int b) { if (b < a) a = b; }

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int c, n; cin >> c >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		a[i] = to_bin(s, c);
	}

	vector<int> dist(1 << c, c);
	for (int i = 0; i < n; i++)
		dist[a[i]] = 0;

	for (int i = 0; i < c; i++)
		for (int mask = 0; mask < (1 << c); mask++)
			chmin(dist[mask ^ (1 << i)], dist[mask] + 1);

	for (int i = 0; i < n; i++) {
		int x = a[i] ^ ((1 << c) - 1);
		cout << c - dist[x] << nl;
	}
	return 0;
}
