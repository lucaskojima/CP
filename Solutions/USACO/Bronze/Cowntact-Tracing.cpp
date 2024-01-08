#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("tracing");

	int n, t; cin >> n >> t;
	
	string s; cin >> s;
	vector<int>cow(n+1);
	for(int i=0; i<n; i++) cow[i+1]=(s[i]-'0');
	
	vector<array<int, 3>>log;
	for(int i=0; i<t; i++){
		int a, b, c; cin >> a >> b >> c;
		log.push_back({a, b, c});
	}
	
	sort(log.begin(), log.end());
	
	auto ok=[&](int ini, int k){
		vector<int>inf(n+1);
		vector<int>greet(n+1);
		
		inf[ini]=1;
		for(auto [x, a, b] : log){
			if(inf[a]==1) greet[a]++;
			if(inf[b]==1) greet[b]++;
			if(inf[a]==1 && greet[a]<=k) inf[b]=1;
			if(inf[b]==1 && greet[b]<=k) inf[a]=1;
		}
		
		for(int i=1; i<=n; i++){
			if(inf[i]!=cow[i]) return false;
		}
		return true;
	};
	
	int ans=0, min_k=1e9, max_k=-1e9;
	for(int i=1; i<=n; i++){
		bool add=false;
		if(cow[i]==1){
			for(int k=0; k<=t; k++){
				if(ok(i, k)){
					add=true;
					min_k=min(min_k, k);
					max_k=max(max_k, k);
				}
			}
		}
		if(add) ans++;
	}
	
	if(max_k==t) cout << ans << " " << min_k << " " << "Infinity";
	else cout << ans << " " << min_k << " " << max_k;
	return 0;
}
