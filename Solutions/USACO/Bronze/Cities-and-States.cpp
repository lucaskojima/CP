#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("citystate");

	int n; cin >> n;
	
	map<string, int>mp;
	int ans=0;
	for(int i=0; i<n; i++){
		string a, b; cin >> a >> b;
		a=a.substr(0, 2);
		
		mp[a+b]++;
		if(a!=b) ans+=mp[b+a];
	}
	
	cout << ans << '\n';
	return 0;
}
