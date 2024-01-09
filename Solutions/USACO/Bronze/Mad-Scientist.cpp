#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN=1010;
int marc[MAXN];

int main(){
	setIO("breedflip");

	int n; cin >> n;
	string a, b; cin >> a >> b;
	
	int ans=0;
	for(int i=0; i<n; i++){
		if(a[i]!=b[i]) marc[i]=1;
		if(a[i]!=b[i] && (i==0 || marc[i-1]==0)) ans++;
	}
	
	cout << ans;
	return 0;
}
