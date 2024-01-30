#include "bits/stdc++.h"
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int>v(n); for(auto &x : v) cin >> x;
	
	set<int>ans;
	for(int i=0; i<n; i++){
		if((i+1<n && v[i]==v[i+1]) || (i+2<n && v[i]==v[i+2])){
			ans.insert(v[i]);
		}
	}
	
	if(ans.empty()){
		cout << "-1\n";
	} else {
		int k=0;
		for(auto x : ans){
			if(k==0) cout << x;
			else cout << " " << x;
			k++;
		}
		cout << '\n';
	}
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
