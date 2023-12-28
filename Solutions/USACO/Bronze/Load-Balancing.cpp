#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("balancing");

	int n, b; cin >> n >> b;
	vector<int>x(n), y(n);
	vector<int>fx, fy;
	
	for(int i=0; i<n; i++){
		cin >> x[i] >> y[i];
		fx.push_back(x[i]+1);
		fy.push_back(y[i]+1);
	}
	
	int ans=1e9;
	for(auto rx : fx){
		for(auto ry : fy){
			int tl=0, tr=0, bl=0, br=0;
			
			for(int i=0; i<n; i++){
				if(x[i]<rx && y[i]<ry) tl++;
				if(x[i]<rx && y[i]>ry) tr++;
				if(x[i]>rx && y[i]<ry) bl++;
				if(x[i]>rx && y[i]>ry) br++;
			}
			
			ans=min(ans, max({tl, tr, bl, br}));
		}
	}
	
	cout << ans;
	return 0;
}
