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

struct point {
	int id, x, y;
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n; cin >> n;

	vector<point> v;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		v.push_back({i, x, y});
	}

	sort(all(v), [](point a, point b) {
		if (a.x != b.x) return a.x < b.x;
		return a.y < b.y;
	});

	vector<pair<int, pii>> edges;
	vector<int> marc(11, -1);

	for (int i = 0; i < n; i++) {
		for (int y = 0; y <= 10; y++) {
			if (marc[y] != -1) {
				point a = v[i], b = v[marc[y]];
				int d = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
				edges.push_back({d, {a.id, b.id}});
			}
		}
	}
	return 0;
}
