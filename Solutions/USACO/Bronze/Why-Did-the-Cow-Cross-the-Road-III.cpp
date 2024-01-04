#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("cowqueue");

	int n; cin >> n;
	
	vector<pair<int, int>>v;
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		v.push_back({a, b});
	}
	
	sort(v.begin(), v.end());
	
	vector<int>ans={0};
	for(int i=0; i<n; i++){
		if(v[i].ff<ans.back()){
			ans.push_back(ans.back()+v[i].ss);
		} else {
			ans.push_back({v[i].ff+v[i].ss});
		}
	}
	
	cout << ans.back();
	return 0;
}
