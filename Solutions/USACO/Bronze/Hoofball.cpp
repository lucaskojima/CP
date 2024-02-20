#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN=1e3+10;
int receive[MAXN], pass[MAXN];

int main(){
	setIO("hoofball");

	int n; cin >> n;
	vector<int>v(n); for(auto &x : v) cin >> x;
	
	sort(v.begin(), v.end());
	
	for(int i=0; i<n; i++){
		int dist=1e9, x;
		for(int j=0; j<n; j++){
			if(i!=j && abs(v[i]-v[j])<dist){
				dist=abs(v[i]-v[j]);
				x=j;
			}
		}
		pass[i]=x;
		receive[x]++;
	}
	
	int ans=0, k=0;
	for(int i=0; i<n; i++){
		if(receive[i]==0) ans++;
		if(receive[i]==1 && receive[pass[i]]==1 && pass[pass[i]]==i) k++;
	}
	
	cout << ans+(k/2);
	return 0;
}
