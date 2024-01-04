#include "bits/stdc++.h"
using namespace std;

#define int long long 

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int>v(n); for(auto &x : v) cin >> x;
	
	sort(v.begin(), v.end());
	
	int s=0, ans;
	for(int i=0; i<n; i++){
		int k=v[i]*(n-i);
		if(k>s){
			s=k;
			ans=v[i];
		}
	}
	
	cout << s << " " << ans;
	return 0;
}
