#include "bits/stdc++.h"
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

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

struct DSU{
	vector<int>pai, rank;

	DSU(int n){
		pai.resize(n), rank.resize(n);
		for(int i=1; i<n; i++) pai[i]=i;
	}

	int find(int v){
		if(pai[v]==v) return v;
		return pai[v]=find(pai[v]);
	}

	void une(int a, int b){
		a=find(a), b=find(b);
		if(a==b) return;
		if(rank[a]>rank[b]) swap(a, b);

		pai[a]=b;
		if(rank[a]==rank[b]) rank[b]++;
	}
};

int main(){
	setIO("wormsort");
	
	int n, m; cin >> n >> m;
	vector<int>v(n); for(auto &x : v) cin >> x;

	vector<pair<pii, int>>edges;
	for(int i=0; i<m; i++){
		int a, b, w; cin >> a >> b >> w;
		edges.push_back({{a, b}, w});
	}


	auto ok = [&](int x) -> bool{
		DSU dsu(n+1);

		for(auto [aux, w] : edges){
			auto [a, b]=aux;
			if(w>=x) dsu.une(a, b);
		}

		for(int i=1; i<=n; i++){
			if(dsu.find(i)!=dsu.find(v[i-1])) return false;
		}
		return true;
	};

	int l=0;     // l is good
	int r=1e9+1; // r is bad

	while(r>l+1){
		int m=(r+l)/2;
		if(ok(m)) l=m;
		else r=m;
	}

	cout << (l==1e9 ? -1 : l) << nl;
	return 0;
}
