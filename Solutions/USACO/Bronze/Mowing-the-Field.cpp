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

int main(){
	setIO("mowing");
	
	int n; cin >> n;
	
	map<pii, int>mp; mp[{0, 0}]=0;
	int t=0, ans=1e9; pii p={0, 0};
	
	for(int i=0; i<n; i++){
		char d; int s; cin >> d >> s;
		
		if(d=='N'){
			for(int j=0; j<s; j++){
				p.ff++; t++;
				if(mp.find(p)!=mp.end()) ans=min(ans, t-mp[p]);
				mp[p]=t;
			}
		}
		if(d=='E'){
			for(int j=0; j<s; j++){
				p.ss++; t++;
				if(mp.find(p)!=mp.end()) ans=min(ans, t-mp[p]);
				mp[p]=t;
			}
		}
		if(d=='S'){
			for(int j=0; j<s; j++){
				p.ff--; t++;
				if(mp.find(p)!=mp.end()) ans=min(ans, t-mp[p]);
				mp[p]=t;
			}
		}
		if(d=='W'){
			for(int j=0; j<s; j++){
				p.ss--; t++;
				if(mp.find(p)!=mp.end()) ans=min(ans, t-mp[p]);
				mp[p]=t;
			}
		}
	}
	
	if(ans==1e9) cout << "-1";
	else cout << ans;
	return 0;
}
