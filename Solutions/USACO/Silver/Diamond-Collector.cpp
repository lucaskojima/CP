#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

#define int long long
#define ff first
#define ss second

int32_t main(){
	setIO("diamond");

	int n, k; cin >> n >> k;
	vector<int>v(n); for(auto &x : v) cin >> x;
	
	sort(v.begin(), v.end());
	
	int r=0; vector<pair<int, int>>itv;
	for(int l=0; l<n; l++){
		while(v[r]-v[l]<=k && r<n) r++;
		itv.push_back({l, r-1});
	}
	
	vector<int>suff(n+1); suff[n]=0;
	for(int i=n-1; i>=0; i--){
		suff[i]=max(suff[i+1], itv[i].ss-itv[i].ff+1);
	}
	
	int ans=0;
	for(int i=0; i<n; i++){
		ans=max(ans, (itv[i].ss-itv[i].ff+1)+suff[itv[i].ss+1]);
	}
	
	cout << ans << '\n';
	return 0;
}
