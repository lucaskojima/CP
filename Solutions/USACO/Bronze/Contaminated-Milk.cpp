#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

#define ff first
#define ss second

int main(){
	setIO("badmilk");

	int n, m, d, s; cin >> n >> m >> d >> s;
	
	vector<vector<int>>cow(n, vector<int>(m, 110));
	vector<set<int>>milk(m);
	
	for(int i=0; i<d; i++){
		int p, m, t; cin >> p >> m >> t; p--; m--;
		cow[p][m]=min(cow[p][m], t);
		milk[m].insert(p);
	}
	
	vector<pair<int, int>>sick;
	for(int i=0; i<s; i++){
		int p, t; cin >> p >> t; p--;
		sick.push_back({p, t});
	}
	
	int ans=0;
	for(int i=0; i<m; i++){
		bool ok=true;
		for(auto x : sick) if(cow[x.ff][i]>=x.ss) ok=false;
		if(ok) ans=max(ans, (int)milk[i].size());
	}
	
	cout << ans << '\n';
	return 0;
}
