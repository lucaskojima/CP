#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("cbarn");

	int n; cin >> n;
	vector<int>v(n); for(auto &x : v) cin >> x;
	
	int ans=1e9;
	for(int i=0; i<n; i++){
		int sum=0;
		for(int j=0; j<n; j++){
			sum+=j*v[(i+j)%n];
		}
		ans=min(ans, sum);
	}
	
	cout << ans;
	return 0;
}
