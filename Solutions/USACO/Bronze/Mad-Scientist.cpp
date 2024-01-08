#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("breedflip");

	int n; cin >> n;
	string a, b; cin >> a >> b;
	
	int ans=0; bool ok=false;
	for(int i=0; i<n; i++){
		if(a[i]!=b[i]){
			if(!ok){
				ok=true;
				ans++;
			}
		} else {
			ok=false;
		}
	}
	
	cout << ans;
	return 0;
}
