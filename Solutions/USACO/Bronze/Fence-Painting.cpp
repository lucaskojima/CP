#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c, d; cin >> a >> b >> c >> d;
	cout << min(max(b, d)-min(a, c), b-a+d-c);
	return 0;
}
