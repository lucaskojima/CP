#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int marc[26];

int main(){
	setIO("cownomics");

	int n, m; cin >> n >> m;
	vector<string>s(n); for(auto &x : s) cin >> x;
	vector<string>p(n); for(auto &x : p) cin >> x;
	
	int ans=0;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++) marc[s[j][i]-'A']=1;
		bool ok=true;
		for(int j=0; j<n; j++) if(marc[p[j][i]-'A']==1) ok=false;
		if(ok) ans++;
		
		for(int j=0; j<26; j++) marc[j]=0;
	}
	
	cout << ans;
	return 0;
}
