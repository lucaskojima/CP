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
	set<int>comp;

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
		comp.erase(a);
		if(rank[a]==rank[b]) rank[b]++;
	}

};

int main(){
	setIO("closing");

	int n, m; cin >> n >> m;

	vector<vector<int>>adj(n+1);

	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int>v(n); for(auto &x : v) cin >> x;
	reverse(all(v));

	DSU dsu(n+1);
	vector<int>ans, marc(n+1);

	for(int i=0; i<n; i++){
		int x=v[i];
		marc[x]=1;
		dsu.comp.insert(x);

		for(auto k : adj[x]){
			if(marc[k]==1){
				dsu.une(x, k);
			}
		}
		
		ans.push_back(sz(dsu.comp));
	}

	reverse(all(ans));
	for(auto x : ans) cout << (x==1 ? "YES" : "NO") << nl;


	return 0;
}
