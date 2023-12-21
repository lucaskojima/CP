#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int marc1[101], marc2[101];

int main(){
	setIO("speeding");

	int n, m; cin >> n >> m;
	int p=1;
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		for(int j=p; j<=p+a; j++){
			marc1[j]=b;
		}
		p+=a;
	}
	
	p=1;
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b;
		for(int j=p; j<=p+a; j++){
			marc2[j]=b;
		}
		p+=a;
	}
	
	int ans=0;
	for(int i=1; i<=100; i++){
		ans=max(ans, marc2[i]-marc1[i]);
	}
	cout << ans;
	
	return 0;
}
