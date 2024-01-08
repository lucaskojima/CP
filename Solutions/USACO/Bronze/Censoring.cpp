#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("censor");

	string s, t; cin >> s >> t;
	
	string ans;
	for(int i=0; i<s.size(); i++){
		ans.push_back(s[i]);
		if(ans.size()>=t.size() && ans.substr(ans.size()-t.size())==t){
			ans.resize(ans.size()-t.size());
		}
	}
	
	cout << ans;
	return 0;
}
