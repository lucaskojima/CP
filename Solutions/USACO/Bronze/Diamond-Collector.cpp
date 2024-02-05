#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("diamond");

	int n, k; cin >> n >> k;
	vector<int>v(n); for(auto &x : v) cin >> x;
	
	sort(v.begin(), v.end());
	
	int ans=0, l=0;
	for(int r=0; r<n; r++){
		while(v[r]-v[l]>k) l++;
		
		ans=max(ans, r-l+1);
	}
	
	cout << ans;
	return 0;
}
