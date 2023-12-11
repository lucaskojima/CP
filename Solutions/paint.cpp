#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
	setIO("paint");
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c, d; cin >> a >> b >> c >> d;
	cout << min(max(b, d)-min(a, c), b-a+d-c);
	return 0;
}
