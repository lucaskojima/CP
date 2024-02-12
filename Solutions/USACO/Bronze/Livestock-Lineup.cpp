#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

vector<string>v={"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
map<string, int>mp;

int main(){
	setIO("lineup");

	int n; cin >> n;
	
	vector<pair<string, string>>vp;
	for(int i=0; i<n; i++){
		string a, b, t;
		cin >> a >> t >> t >> t >> t >> b;
		vp.push_back({a, b});
	}
	
	sort(v.begin(), v.end());
	
	do{
		for(int i=0; i<(int)v.size(); i++){
			mp[v[i]]=i;
		}
		
		bool ok=true;
		for(int i=0; i<(int)vp.size(); i++){
			if(abs(mp[vp[i].ff]-mp[vp[i].ss])>1) ok=false;
		}
		if(ok) break;
		
	} while(next_permutation(v.begin(), v.end()));
	
	for(auto x : v) cout << x << '\n';
	return 0;
}
