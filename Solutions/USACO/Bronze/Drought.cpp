#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

void solve(){
	int n; cin >> n;
	vector<int>v(n); for(auto &x : v) cin >> x;
	
	ll ans=0;
	for(int i=0; i<n-1; i++){
		if(v[i]<v[i+1]){
			if(i+2>=n) {cout << "-1\n"; return;}
			
			ll k=v[i+1]-v[i];
			v[i+1]-=k; v[i+2]-=k;
			ans+=2*k;
			
			if(v[i+2]<0) {cout << "-1\n"; return;}
		}
		if(v[i]>v[i+1]){
			if(i%2==0) {cout << "-1\n"; return;}
			
			ll k=v[i]-v[i+1];
			ans+=(i+1)*k;
		}
	}
	
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
