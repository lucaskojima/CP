#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

struct type{
	int d;
	string n;
	int m;
};

int main(){
	setIO("measurement");

	int n; cin >> n;
	
	vector<type>v(n);
	for(int i=0; i<n; i++){
		int d; string n; int m;
		cin >> d >> n >> m;
		v[i]={d, n, m};
	}
	
	sort(v.begin(), v.end(), [&](type a, type b){
		if(a.d!=b.d) return (a.d<b.d);
		return a.m<b.m;
	});
	
	int ans=0;
	int b=7, e=7, m=7;
	for(int i=0; i<n; i++){
		int old_max=max({b, e, m});
		set<string>old_m;
		if(b==old_max) old_m.insert("Bessie");
		if(e==old_max) old_m.insert("Elsie");
		if(m==old_max) old_m.insert("Mildred");
		
		if(v[i].n=="Bessie") b+=v[i].m;
		if(v[i].n=="Elsie") e+=v[i].m;
		if(v[i].n=="Mildred") m+=v[i].m;
		
		int new_max=max({b, e, m});
		set<string>new_m;
		if(b==new_max) new_m.insert("Bessie");
		if(e==new_max) new_m.insert("Elsie");
		if(m==new_max) new_m.insert("Mildred");
		
		if(old_m!=new_m) ans++;
	}
	cout << ans;
	
	return 0;
}
