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

struct tiles {
	int h, id;
};

struct boots {
	int s, d, id;
};

void setIO(string s) {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main() {
	setIO("snowboots");

	int n, q; cin >> n >> q;

	vector<tiles> tile;
	for (int i = 0; i < n; i++) {
		int h; cin >> h;
		tile.push_back({h, i});
	}

	vector<boots> boot;
	for (int i = 0; i < q; i++) {
		int s, d; cin >> s >> d;
		boot.push_back({s, d, i});
	}

	sort(all(tile), [](const auto &a, const auto &b){
		return a.h > b.h;
	});
	sort(all(boot), [](const auto &a, const auto &b){
		return a.s > b.s;
	});

	vector<int> nxt(n), prv(n);
	for (int i = 0; i < n; i++) {
		nxt[i] = i + 1;
		prv[i] = i - 1;
	}

	vector<int> ans(q);
	int pos = 0, max_d = 1;

	for (auto [s, d, i] : boot) {
		while (s < tile[pos].h) {
			int id = tile[pos].id;
			nxt[prv[id]] = nxt[id];
			prv[nxt[id]] = prv[id];

			max_d = max(max_d, nxt[id] - prv[id]);
			pos++;
		}

		ans[i] = (d >= max_d ? 1 : 0);
	}

	for (auto x : ans) cout << x << nl;
	return 0;
}
