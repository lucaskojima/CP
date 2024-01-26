#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

#define ff first
#define ss second
typedef pair<int, int> pii;

int main(){
	setIO("buckets");

	pii ini, fim, r;
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			char a; cin >> a;
			if(a=='B') ini={i, j};
			if(a=='L') fim={i, j};
			if(a=='R') r={i, j};
		}
	}
	
	int ans=abs(ini.ff-fim.ff)+abs(ini.ss-fim.ss)-1;
	if((ini.ff==r.ff && fim.ff==r.ff && (ini.ss<r.ss && r.ss<fim.ss || fim.ss<r.ss && r.ss<ini.ss)) || (ini.ss==r.ss && fim.ss==r.ss) && (ini.ff<r.ff && r.ff<fim.ff || fim.ff<r.ff && r.ff<ini.ff)) ans+=2;
	
	cout << ans;
	
	return 0;
}
