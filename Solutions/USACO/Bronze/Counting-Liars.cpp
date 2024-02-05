#include "bits/stdc++.h"
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	
	vector<int>l, g;
	for(int i=0; i<n; i++){
		char c; int p; cin >> c >> p;
		if(c=='L') l.push_back(p);
		if(c=='G') g.push_back(p);
	}
	
	sort(l.rbegin(), l.rend());
	sort(g.begin(), g.end());
	
	int k=1;
	for(int i=0; i<g.size(); i++){
		for(int j=0; j<l.size(); j++){
			if(l[j]>=g[i]) k=max(k, i+j+2);
		}
	}
	
	cout << n-k;
	return 0;
}
