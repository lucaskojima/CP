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

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n; cin >> n;

  vector<int> p(n + 1), dep(n + 1), cnt(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    dep[i] = dep[p[i]] + 1;
    cnt[p[i]]++;
  }

  int x;
  while (cin >> x) {
    while (x != 0 && cnt[p[x]] == 1)
      x = p[x];

    cout << dep[x] << endl;
    if (x != 0)
      cnt[p[x]]--;
  }
  return 0;
}

