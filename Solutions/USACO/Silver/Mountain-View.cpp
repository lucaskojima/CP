#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

struct type{int l, r;};

int main(){
	setIO("mountains");

	int n; cin >> n;
	
	vector<type>v;
	for(int i=0; i<n; i++){
		int x, y; cin >> x >> y;
		v.push_back({x-y, x+y});
	}
	
	sort(v.begin(), v.end(), [](const type &a, const type &b){
		if(a.l!=b.l) return a.l<b.l;
		return a.r>b.r;
	});
	
	int maxr=0, in=0;
	for(int i=0; i<n; i++){
		if(v[i].r<=maxr) in++;
		maxr=max(maxr, v[i].r);
	}
	
	cout << n-in;
	return 0;
}
