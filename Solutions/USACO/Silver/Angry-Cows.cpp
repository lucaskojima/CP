#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("angry");

	int n, k; cin >> n >> k;
	vector<int>v(n); for(auto &x : v) cin >> x;
	
	sort(v.begin(), v.end());
	
	auto ok=[&](int x){
		int count=1, p=v[0]+x;
		for(int i=0; i<n; i++){
			if(abs(v[i]-p)>x){
				p=v[i]+x;
				count++;
			}
		}
		return count<=k;
	};
	
	int l=-1; // l is bad
	int r=1;  // r is good
	while(!ok(r)) r*=2;
	
	while(r>l+1){
		int m=(r+l)/2;
		if(ok(m)) r=m;
		else l=m;
	}
	
	cout << r << '\n';
	return 0;
}
