#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, k; cin >> n >> k;
	vector<ll>v(n); for(auto &x : v) cin >> x;
	
	ll ans=k+1;
	for(int i=0; i<n-1; i++){
		ans+=min(k+1, v[i+1]-v[i]);
	}
	
	cout << ans;
	return 0;
}
