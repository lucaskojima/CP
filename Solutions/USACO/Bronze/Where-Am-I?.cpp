#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("whereami");

	int n; cin >> n;
	string s; cin >> s;
	
	int ans=1e9;
	for(int k=1; k<n; k++){
		set<string>st; bool ok=true;
		for(int i=0; i<n; i++){
			string aux=s.substr(i, k);
			if(st.count(aux)) ok=false;
			st.insert(aux);
		}
		if(ok) ans=min(ans, k);
	}
	
	cout << ans;
	return 0;
}
