#include "bits/stdc++.h"
using namespace std;

const int MAXN=1e4;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int>v;
	for(int i=1; i*i<=MAXN; i++) v.push_back(i*i);
	
	vector<int>dp(MAXN+1, 1e9); dp[0]=0;
	for(int i=1; i<=MAXN; i++){
		for(auto x : v){
			if(i-x<0) break;
			dp[i]=min(dp[i], dp[i-x]+1);
		}
	}
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}
