#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
typedef pair<int, int> pii;

const int INF=1e9;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("traffic");

	int n; cin >> n;
	vector<pair<pii, string>>v;
	for(int i=0; i<n; i++){
		string s; cin >> s;
		int a, b; cin >> a >> b;
		v.push_back({{a, b}, s});
	}
	
	pii fim={0, INF};
	for(int i=0; i<n; i++){
		if(v[i].ss=="none"){
			fim.ff=max(fim.ff, v[i].ff.ff);
			fim.ss=min(fim.ss, v[i].ff.ss);
		}
		if(v[i].ss=="on"){
			fim.ff+=v[i].ff.ff;
			fim.ss+=v[i].ff.ss;
		}
		if(v[i].ss=="off"){
			fim.ff-=v[i].ff.ss;
			fim.ss-=v[i].ff.ff;
			
			fim.ff=max(fim.ff, 0);
		}
	}
	
	pii ini={0, INF};
	for(int i=n-1; i>=0; i--){
		if(v[i].ss=="none"){
			ini.ff=max(ini.ff, v[i].ff.ff);
			ini.ss=min(ini.ss, v[i].ff.ss);
		}
		if(v[i].ss=="on"){
			ini.ff-=v[i].ff.ss;
			ini.ss-=v[i].ff.ff;
			
			ini.ff=max(ini.ff, 0);
		}
		if(v[i].ss=="off"){
			ini.ff+=v[i].ff.ff;
			ini.ss+=v[i].ff.ss;
		}
	}
	cout << ini.ff << " " << ini.ss << '\n';
	cout << fim.ff << " " << fim.ss << '\n';
	return 0;
}
