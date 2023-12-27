#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
typedef pair<int, int> pii;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

bool val(pii a, pii b, pii c){
	return (a.ff==b.ff && a.ff!=c.ff && a.ss==c.ss && a.ss!=b.ss);
}

int main(){
	setIO("triangles");

	int n; cin >> n;
	vector<pair<int, int>>v(n);
	for(auto &[x, y] : v) cin >> x >> y;
	
	int ans=0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			for(int k=j+1; k<n; k++){
				pii a={v[i].ff, v[i].ss};
				pii b={v[j].ff, v[j].ss};
				pii c={v[k].ff, v[k].ss};
				
				if(val(a, b, c)) ans=max(ans, abs(a.ss-b.ss)*abs(a.ff-c.ff));
				if(val(a, c, b)) ans=max(ans, abs(a.ss-c.ss)*abs(a.ff-b.ff));
				
				if(val(b, a, c)) ans=max(ans, abs(b.ss-a.ss)*abs(b.ff-c.ff));
				if(val(b, c, a)) ans=max(ans, abs(b.ss-c.ss)*abs(b.ff-a.ff));
				
				if(val(c, a, b)) ans=max(ans, abs(c.ss-a.ss)*abs(c.ff-b.ff));
				if(val(c, b, a)) ans=max(ans, abs(c.ss-b.ss)*abs(c.ff-a.ff));
			}
		}
	}
	
	cout << ans;
	return 0;
}
