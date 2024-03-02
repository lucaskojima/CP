#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("bcount");

	int n, q; cin >> n >> q;
	
	vector<int>v(n+1), pref1(n+1), pref2(n+1), pref3(n+1);
	for(int i=1; i<=n; i++){
		cin >> v[i];
		
		if(v[i]==1) pref1[i]++;
		if(v[i]==2) pref2[i]++;
		if(v[i]==3) pref3[i]++;
		pref1[i]+=pref1[i-1];
		pref2[i]+=pref2[i-1];
		pref3[i]+=pref3[i-1];
	}
	
	for(int i=0; i<q; i++){
		int a, b; cin >> a >> b;
		cout << pref1[b]-pref1[a-1] << " ";
		cout << pref2[b]-pref2[a-1] << " ";
		cout << pref3[b]-pref3[a-1];
		
		cout << '\n';
	}
	
	
	return 0;
}
