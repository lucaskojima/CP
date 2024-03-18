#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("lemonade");

	int n; cin >> n;
	vector<int>v(n); for(auto &x : v) cin >> x;
	
	sort(v.rbegin(), v.rend());
	
	int k=0, ans=0;
	for(int i=0; i<n; i++){
		if(v[i]>=k){
			k++;
			ans++;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
