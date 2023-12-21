#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

vector<int> count(string s){
	vector<int>v(26);
	for(auto x : s) v[x-'a']++;
	return v;
}

int main(){
	setIO("blocks");

	int n; cin >> n;
	
	vector<int>ans(26);
	for(int i=0; i<n; i++){
		string a, b; cin >> a >> b;
		vector<int>freq1=count(a);
		vector<int>freq2=count(b);
		
		for(int j=0; j<26; j++){
			ans[j]+=max(freq1[j], freq2[j]);
		}
	}
	
	for(auto x : ans) cout << x << '\n';
	return 0;
}
