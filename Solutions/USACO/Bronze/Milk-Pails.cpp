#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("pails");

	int x, y, m; cin >> x >> y >> m;
	int ans=0;
	for(int i=0; i<1000; i++){
		for(int j=0; j<1000; j++){
			if(x*i+y*j<=m) ans=max(ans, x*i+y*j);
		}
	}
	cout << ans;
	return 0;
}
