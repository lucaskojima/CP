#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

#define int long long

int32_t main(){
	setIO("teamwork");

	int n, k; cin >> n >> k;
	vector<int>v(n); for(auto &x : v) cin >> x;
	
	vector<int>dp(n); int mx=0;
	for(int i=0; i<k; i++){
		mx=max(mx, v[i]);
		dp[i]=mx*(i+1);
	}
	
	for(int i=k; i<n; i++){
		int cur=v[i];
		for(int j=i; j>=i-k+1; j--){
			cur=max(cur, v[j]);
			dp[i]=max(dp[i], dp[j-1]+cur*(i-j+1));
		}
	}
	
	cout << dp[n-1];
	return 0;
}
