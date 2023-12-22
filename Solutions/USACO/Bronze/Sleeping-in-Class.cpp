#include "bits/stdc++.h"
using namespace std;

void solve(){
	int n; cin >> n;
	int v[n+1], pref[n+1];
	pref[0]=0;
	for(int i=1; i<=n; i++){
		cin >> v[i];
		pref[i]=pref[i-1]+v[i];
	}
	
	int ans=1e9, sum=pref[n];
	for(int i=1; i<=n; i++){
		int x=pref[i];
		if(x!=0 && sum%x!=0) continue;
		
		int aux=0, count=i-1;
		bool ok=true;
		for(int k=i+1; k<=n; k++){
			aux+=v[k];
			if(aux<x) count++;
			if(aux==x) aux=0;
			if(aux>x) {ok=false; break;}
		}
		
		if(ok) ans=min(ans, count);
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
