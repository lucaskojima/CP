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
			res += (1 << i);
	return res;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int c, n; cin >> c >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		a[i] = to_bin(s, c);
	}

	vector<vector<int>> adj(1 << c);
	// aresta entre v_i e v_j <-> v_i e v_j diferem em um bit
	// menor distancia = numeros de bits diferentes

	for (int i = 0; i < (1 << c); i++)
		for (int j = 0; j < c; j++)
			adj[i].push_back(i ^ (1 << j));

	vector<int> dist(1 << c, INF);
	// dist[i] = menor qnt de bits difentes entre i e a[k], 0 <= k < n

	queue<int> q;
	for (int i = 0; i < n; i++) {
		dist[a[i]] = 0;
		q.push(a[i]);
	}

	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int k : adj[x]) {
			if (dist[k] != INF) continue;
			dist[k] = dist[x] + 1;
			q.push(k);
		}
	}

	for (int i = 0; i < n; i++) {
		int inv = a[i] ^ ((1 << c) - 1);
		// pq inv?
		// - maximizar bits diferentes em a[i] = minimizar bits diferentes em inv
		// - pegar resultado da bfs multisource (dist[a[i]] = 0)

		cout << c - dist[inv] << nl;
	}
	return 0;
}
