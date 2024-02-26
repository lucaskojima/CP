#include "bits/stdc++.h"
using namespace std;

#define int long long

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main(){
	setIO("div7");

	int n; cin >> n;
	
	vector<int>pref(n+1);
	for(int i=1; i<=n; i++){
		cin >> pref[i];
		pref[i]+=pref[i-1];
	}
	
	vector<int>marc(7, -1);
	marc[0]=0;
	int ans=0;
	for(int i=1; i<=n; i++){
		if(marc[pref[i]%7]!=-1){
			ans=max(ans, i-marc[pref[i]%7]);
		} else {
			marc[pref[i]%7]=i;
		}
	}
	
	cout << ans;
	return 0;
}
