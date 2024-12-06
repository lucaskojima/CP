#include <bits/stdc++.h>
using namespace std;

const int n = 1e6;

int main () {
    int l = 1, r = n;
    
    int minidx = n;
    while (l <= r) {
        int m = l + (r - l) / 2;
        cout << m << endl;

        string a;
        cin >> a;

        if (a == "<") {
            r = m - 1;
        } else {
            minidx = min(minidx, m);
            l = m + 1;
        }
    }
    cout << minidx << endl;
}
