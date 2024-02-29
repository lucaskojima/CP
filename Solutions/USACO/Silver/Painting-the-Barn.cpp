#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN=1010;
int pref[MAXN][MAXN];

int main(){
	setIO("paintbarn");

	int n, k; cin >> n >> k;

	for(int i=0; i<n; i++){
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		pref[x1][y1]++;
		pref[x2][y2]++;
		pref[x1][y2]--;
		pref[x2][y1]--;
	}
	
	int ans=0;
	for(int i=0; i<MAXN; i++){
		for(int j=0; j<MAXN; j++){
			if(i>0) pref[i][j]+=pref[i-1][j];
			if(j>0) pref[i][j]+=pref[i][j-1];
			if(i>0 && j>0) pref[i][j]-=pref[i-1][j-1];
			
			if(pref[i][j]==k) ans++;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
