#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("teleport.in", "r", stdin);
	freopen("teleport.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, x, y; cin >> a >> b >> x >> y;
	if(a>b) swap(a, b);
	if(x>y) swap(x, y);
	cout << min({b-a, abs(x-a)+abs(y-b)});
	return 0;
}
