#include "bits/stdc++.h"
using namespace std;


void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("outofplace");

	int n; cin >> n;
	
	vector<int>v;
	for(int i=0; i<n; i++){
		int a; cin >> a;
		if(v.empty() || (!v.empty() && v.back()!=a)) v.push_back(a);
	}
	
	int ans=0;
	for(int i=1; i<v.size(); i++){
		for(int j=i; j>0; j--){
			if(v[j]<v[j-1]){
				swap(v[j], v[j-1]);
				ans++;
			} else {
				break;
			}
		}
	}
	
	cout << ans;
	return 0;
}
