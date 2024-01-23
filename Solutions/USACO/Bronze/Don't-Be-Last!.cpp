#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

map<string, int>mp={{"Bessie", 0}, {"Elsie", 0}, {"Daisy", 0}, {"Gertie", 0}, {"Annabelle", 0}, {"Maggie", 0}, {"Henrietta", 0}};

int main(){
	setIO("notlast");
	
	int n; cin >> n;
	for(int i=0; i<n; i++){
		string a; int b; cin >> a >> b;
		mp[a]+=b;
	}
	
	int m=1e9, k=1e9;
	string ans;
	for(auto [x, y] : mp){
		if(y<m) m=y;
	}
	for(auto [x, y] : mp){
		if(y!=m && y<k) k=y;
	}
	int ok=0;
	for(auto [x, y] : mp){
		if(y==k){
			ans=x;
			ok++;
		}
	}
	
	cout << (ok==1 ? ans : "Tie") << '\n';
	return 0;
}
