// nao passou no testcase 5 e 10. (Nao quero debugar)
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

struct T {
	int day, id, delta;
};

void setIO(string s) {
	ios::sync_with_stdio(0), cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main() {
	setIO("measurement");

	int n, g; cin >> n >> g;

	vector<T> v(n);
	for (auto &x : v) {
		cin >> x.day >> x.id >> x.delta;
	}

	sort(all(v), [](const T &a, const T &b){
		return a.day < b.day;
	});

	map<int, int> cow, cnt;
	int ans = 0;

	for (int i = 1; i <= n; i++) cow[i] = g;
	cnt[g] = n;

	for (int i = 0; i < n; i++) {
		auto [day, id, delta] = v[i];

		bool was_top = cow[id] == cnt.rbegin()->ff;
		int prev_qnt = cnt[cow[id]];

		cnt[cow[id]]--;
		if (cnt[cow[id]] == 0) cnt.erase(cow[id]);
		cow[id] += delta;
		cnt[cow[id]]++;

		bool is_top = cow[id] == cnt.rbegin()->ff;
		int qnt = cnt[cow[id]];

		if (was_top) {
			if (is_top && qnt == prev_qnt) continue;
			ans++;
		} else if (is_top) {
			ans++;
		}
	}

	cout << ans << nl;
	return 0;
}
