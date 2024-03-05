#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

struct type{int l, r;};

int main(){
	setIO("lifeguards");

	int n; cin >> n;
	
	vector<type>v;
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		v.push_back({a, b});
	}
	
	sort(v.begin(), v.end(), [](const type &a, const type &b){
		if(a.l!=b.l) return a.l<b.l;
		return a.r>b.r;
	});
	
	int time=0, maxr=0;
	for(int i=0; i<n; i++){
		time+=max(v[i].r-max(v[i].l, maxr), 0);
		maxr=max(maxr, v[i].r);
	}
	
	int mtime=1e9; maxr=0;
	v.push_back({v[n-1].r, 0});
	for(int i=0; i<n; i++){
		mtime=min(mtime, min(v[i].r, v[i+1].l)-max(v[i].l, maxr));
		maxr=max(maxr, v[i].r);
	}
	
	cout << time-max(mtime, 0);
	return 0;
}
