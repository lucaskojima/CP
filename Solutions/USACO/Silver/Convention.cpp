#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("convention");

	int n, m, c; cin >> n >> m >> c;
	vector<int>v(n); for(auto &x : v) cin >> x;
	
	sort(v.begin(), v.end());
	
	auto ok=[&](int x){
		int k=v[0], cow=0, count=1;
		for(int i=0; i<n; i++){
			if(v[i]-k>x || cow>=c){
				k=v[i];
				cow=0;
				count++;
			}
			cow++;
		}
		return count<=m;
	};
	
	int l=-1; // l is bad
	int r=1;  // r is good
	while(!ok(r)) r*=2;
	
	while(r>l+1){
		int m=(l+r)/2;
		if(ok(m)) r=m;
		else l=m;
	}
	
	cout << r << '\n';
	return 0;
}
