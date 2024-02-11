#include "bits/stdc++.h"
using namespace std;

const int MAXN=110;
int n, m, ans=1e9, stall[MAXN];
vector<array<int, 4>>v;

void bt(int idx, int c){
	if(idx==m){
		bool ok=true; vector<int>aux(MAXN);
		for(int i=1; i<=100; i++){
			aux[i]=stall[i]+aux[i-1];
			if(aux[i]>0) ok=false;
		}
		
		if(ok) ans=min(ans, c);
		return;
	}
	
	stall[v[idx][0]]-=v[idx][2];
	stall[v[idx][1]+1]+=v[idx][2];
	bt(idx+1, c+v[idx][3]);
	
	stall[v[idx][0]]+=v[idx][2];
	stall[v[idx][1]+1]-=v[idx][2];
	bt(idx+1, c);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		int s, t, c; cin >> s >> t >> c;
		stall[s]+=c;
		stall[t+1]-=c;
	}
	
	for(int i=0; i<m; i++){
		int a, b, p, m; cin >> a >> b >> p >> m;
		v.push_back({a, b, p, m});
	}
	
	bt(0, 0);
	
	cout << ans;
	return 0;
}
