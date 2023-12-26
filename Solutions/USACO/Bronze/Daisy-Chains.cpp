#include "bits/stdc++.h"
using namespace std;

const int MAXN=1010;
int marc[MAXN];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int>v(n); for(auto &x : v) cin >> x;
	
	int ans=n;
	for(int i=0; i<n; i++){
		int k=v[i]; marc[v[i]]=1;
		for(int j=i+1; j<n; j++){
			k+=v[j]; marc[v[j]]=1;
			if(marc[k/(j-i+1)]==1 && k%(j-i+1)==0) ans++;
		}
		
		for(int j=0; j<n; j++) marc[v[j]]=0;
	}
	
	cout << ans;
	return 0;
}
