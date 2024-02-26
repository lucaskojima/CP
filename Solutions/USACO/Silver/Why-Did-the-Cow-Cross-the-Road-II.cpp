#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("maxcross");

	int n, k, b; cin >> n >> k >> b;
	
	vector<int>pref(n+1);
	for(int i=0; i<b; i++){
		int a; cin >> a;
		pref[a]++;
	}
	
	for(int i=1; i<=n; i++) pref[i]+=pref[i-1];
	
	int ans=1e9;
	for(int i=1; i<=n-k+1; i++){
		ans=min(ans, pref[i+k-1]-pref[i-1]);
	}
	
	cout << ans;
	return 0;
}
