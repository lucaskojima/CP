#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("highcard");

	int n; cin >> n;
	
	vector<int>marc(2*n);
	for(int i=0; i<n; i++){
		int a; cin >> a;
		marc[--a]++;
	}
	
	int k=0, ans=0;
	for(int i=0; i<2*n; i++){
		if(marc[i]==1) k++;
		if(marc[i]==0 && k>0){
			k--;
			ans++;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
