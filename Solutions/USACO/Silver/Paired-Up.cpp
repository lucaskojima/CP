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
	setIO("pairup");

	int n; cin >> n;
	
	vector<pair<int, int>>v;
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		v.push_back({b, a});
	}
	
	sort(v.begin(), v.end());
	
	int ans=0, l=0, r=n-1;
	while(l<=r){
		ans=max(ans, v[l].ff+v[r].ff);
		if(v[l].ss==v[r].ss){
			l++;
			r--;
		} else if(v[l].ss<v[r].ss){
			v[r].ss-=v[l].ss;
			l++;
		} else if(v[l].ss>v[r].ss){
			v[l].ss-=v[r].ss;
			r--;
		}
	}
	
	cout << ans;
	return 0;
}
