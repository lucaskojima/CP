#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("sleepy");

	int n; cin >> n;
	vector<int>v(n); for(auto &x : v) cin >> x;
	
	int sorted=1;
	for(int i=n-1; i>=0; i--){
		if(v[i]>v[i-1]) sorted++;
		else break;
	}
	
	cout << (is_sorted(v.begin(), v.end()) ? 0 : n-sorted) << '\n';
	return 0;
}
