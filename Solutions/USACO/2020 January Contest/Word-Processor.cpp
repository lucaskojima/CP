#include "bits/stdc++.h"
using namespace std;

int main(){
	freopen("word.in", "r", stdin);
	freopen("word.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k; cin >> n >> k;
	vector<string>v;
	for(int i=0; i<n; i++){
		string s; cin >> s;
		v.push_back(s);
	}
	int count=0;
	for(int i=0; i<n; i++){
		if(count+v[i].size()<=k){
			if(count!=0) cout << " ";
			cout << v[i];
			count+=v[i].size();
		} else {
			cout << '\n' << v[i];
			count=v[i].size();
		}
	}
	return 0;
}
