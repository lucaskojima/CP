#include "bits/stdc++.h"
using namespace std;

int main(){
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	vector<int>ord(n); for(auto &x : ord) cin >> x;
	vector<string>v0(n); for(auto &x : v0) cin >> x;
	vector<string>v1(n), v2(n), v3(n);
	
	for(int i=1; i<=3; i++){
		for(int k=0; k<n; k++){
			if(i==1) v1[k]=v0[ord[k]-1];
			if(i==2) v2[k]=v1[ord[k]-1];
			if(i==3) v3[k]=v2[ord[k]-1];
		}
	}
	
	for(int i=0; i<n; i++){
		cout << v3[i] << '\n';
	}
	return 0;
}
