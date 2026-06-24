#include "bits/stdc++.h"
#define sz(x) int(size(x))

using namespace std;

const int M = 1e9 + 9;
const int B = 67;

int hext(int h, int a) {
  return (1LL * h * B + a) % M;
}

int main() {
  freopen("censor.in", "r", stdin);
  freopen("censor.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0);

  string a, b; cin >> a >> b;

  int hsh_b = 0;
  for (int i = 0; i < sz(b); i++)
    hsh_b = hext(hsh_b, b[i]);

  vector<int> pow(sz(b) + 1);
  pow[0] = 1;
  for (int i = 1; i < sz(pow); i++)
    pow[i] = 1LL * pow[i - 1] * B % M;

  vector<int> hsh_r{0};
  string r;

  for (int i = 0; i < sz(a); i++) {
    hsh_r.push_back(hext(hsh_r.back(), a[i]));
    r += a[i];

    if (sz(r) >= sz(b)) {
      int hsub = 1LL * hsh_r[sz(r) - sz(b)] * pow[sz(b)] % M;
      int hsh = (hsh_r.back() - hsub + M) % M;

      if (hsh == hsh_b) {
        r.resize(sz(r) - sz(b));
        hsh_r.resize(sz(hsh_r) - sz(b));
      }
    }
  }

  cout << r << '\n';
  return 0;
}

