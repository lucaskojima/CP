#include "bits/stdc++.h"
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define int long long

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const char nl = '\n';
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main(){
	setIO("hayfeast");

	int n, k; cin >> n >> k;

	vector<int>pref(n+1);
	vector<pii>v(n+1);
	
	for(int i=1; i<=n; i++){
		cin >> v[i].ff >> v[i].ss;
		pref[i]=pref[i-1]+v[i].ff;
	}

	multiset<int>ms;
	
	auto add = [&](int idx) -> void{
		ms.insert(v[idx].ss);
	};
	auto good = [&](int l, int r) -> bool{
		return pref[r]-pref[l-1]>=k;
	};
	auto remove = [&](int idx) -> void{
		ms.erase(ms.find(v[idx].ss));
	};


	int l=1, ans=LINF;
	for(int r=1; r<=n; r++){
		add(r);
		while(good(l+1, r) && l<r){
			remove(l);
			l++;
		}
		if(good(l, r)) ans=min(ans, *ms.rbegin());
	}

	cout << ans << nl;
	return 0;
}
