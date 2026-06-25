#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#define sz(x) int(size(x))

using namespace std;
using namespace __gnu_pbds;

const int M = 1e9 + 9;
const int B = 67;

int mul(int a, int b) {
  return 1LL * a * b % M;
}

struct hashed_string {
  vector<int> hsh, pow;
  hashed_string(const string &s) : hsh(sz(s) + 1), pow(sz(s) + 1, 1) {
    for (int i = 0; i < sz(s); i++)
      hsh[i + 1] = (mul(hsh[i], B) + s[i]) % M,
      pow[i + 1] = mul(pow[i], B);
  }
  int get_hash(int l, int r) {
    return (hsh[r + 1] - mul(hsh[l], pow[r - l + 1]) + M) % M;
  }
};

int main() {
  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m; cin >> n >> m;

  vector<hashed_string> ha, hb;
  for (int i = 0; i < n; i++) {
    string x; cin >> x;
    ha.emplace_back(x);
  }
  for (int i = 0; i < n; i++) {
    string x; cin >> x;
    hb.emplace_back(x);
  }

  for (int t = 1; t < m; t++)
    for (int i = 0, j = t - 1; j < m; i++, j++) {
      gp_hash_table<int, null_type> st;
      for (int k = 0; k < n; k++)
        st.insert(ha[k].get_hash(i, j));

      bool ok = true;
      for (int k = 0; k < n; k++)
        if (st.find(hb[k].get_hash(i, j)) != st.end()) {
          ok = false;
          break;
        }

      if (ok) {
        cout << t << '\n';
        return 0;
      }
    }
  return 0;
}
