#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN=1e5+10;
int inv[MAXN], v[MAXN], aux[MAXN];

void merge(int ini, int fim){
	if(ini==fim) return;
	
	int m=(ini+fim)/2;
	merge(ini, m);
	merge(m+1, fim);
	
	int l=ini, r=m+1;
	for(int i=ini; i<=fim; i++){
		if(r>fim || (l<=m && v[l]<v[r])){
			aux[i]=v[l];
			l++;
		} else {
			aux[i]=v[r];
			inv[v[r]]+=(m-l+1);
			r++;
		}
	}
	for(int i=ini; i<=fim; i++) v[i]=aux[i];
}

int main(){
	setIO("sort");

	int n; cin >> n;
	for(int i=0; i<n; i++) cin >> v[i];
	
	vector<pair<int, int>>idx;
	for(int i=0; i<n; i++){
		idx.push_back({v[i], i});
	}
	sort(idx.begin(), idx.end());
	for(int i=0; i<n; i++){
		v[idx[i].second]=i;
	}
	
	merge(0, n-1);

	int ans=0;
	for(int i=0; i<n; i++){
		ans=max(ans, inv[v[i]]);
	}
	
	cout << ans+1 << '\n';
	return 0;
}
