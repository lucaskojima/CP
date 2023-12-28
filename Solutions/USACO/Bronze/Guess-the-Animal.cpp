#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("guess");

	int n; cin >> n;
	
	vector<set<string>>v(n);
	for(int i=0; i<n; i++){
		string n; int a; cin >> n >> a;
		while(a--){
			string s; cin >> s;
			v[i].insert(s);
		}
	}
	
	int ans=0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int k=0;
			for(auto x : v[i]){
				if(v[j].find(x)!=v[j].end()) k++;
			}
			ans=max(ans, k);
		}
	}
	
	cout << ans+1;
	return 0;
}
