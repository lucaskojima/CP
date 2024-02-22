#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN=1e5+10;
int deg[MAXN];

int main(){
	setIO("planting");

	int n; cin >> n;
	for(int i=0; i<n-1; i++){
		int a, b; cin >> a >> b;
		deg[a]++;
		deg[b]++;
	}
	
	int ans=0;
	for(int i=1; i<=n; i++){
		ans=max(ans, deg[i]);
	}
	
	cout << ans+1 << '\n';
	return 0;
}
