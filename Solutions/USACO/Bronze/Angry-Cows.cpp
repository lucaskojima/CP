#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int n;

bool val(int x){
	return (x>=0 && x<n);
}

int main(){
	setIO("angry");

	cin >> n;
	vector<int>v(n); for(auto &x : v) cin >> x;
	
	sort(v.begin(), v.end());
	
	int ans=0;
	for(int i=0; i<n; i++){
		int l=i, r=i+1, k=1, cnt=1;
		while(r<n){
			while(l<r-1) l++;
			if(v[r]-v[l]>k) break;
			while(val(r) && v[r]-v[l]<=k) r++, cnt++;
			k++;
		}
		
		l=i-1, r=i, k=1;
		while(l>=0){
			while(l<r-1) r--;
			if(v[r]-v[l]>k) break;
			while(val(l) && v[r]-v[l]<=k) l--, cnt++;
			k++;
		}
		ans=max(ans, cnt);
	}
	
	cout << ans;
	return 0;
}
