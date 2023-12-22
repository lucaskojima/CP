#include "bits/stdc++.h"
using namespace std;

const int MAXN=1100;
int marc[MAXN], marc2[MAXN];

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("lifeguards");

	int n; cin >> n;
	vector<pair<int, int>>v;
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		v.push_back({a, b});
		for(int j=a; j<b; j++) marc[j]++;
	}
	
	vector<int>fire(n);
	for(int i=0; i<n; i++){
		int a=v[i].first;
		int b=v[i].second;
		for(int j=a; j<b; j++){
			if(marc[j]==1) fire[i]++;
		}
	}
	
	int menor=1e9, k;
	for(int i=0; i<n; i++){
		if(fire[i]<menor){
			menor=fire[i];
			k=i;
		}
	}
	
	int ans=0;
	for(int i=0; i<n; i++){
		if(i!=k){
			int a=v[i].first;
			int b=v[i].second;
			for(int j=a; j<b; j++){
				if(marc2[j]==0){
					ans++;
					marc2[j]=1;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
