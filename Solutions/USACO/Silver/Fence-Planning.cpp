#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

template<typename T>
using matrix = vector<vector<T>>;
using pii = pair<int, int>;
using ll = long long;

const ll LINF = (1LL<<60);
const int INF = (1<<30);
const int MAXN = 1e5+10;

vector<int>adj[MAXN];
int x, xx, y, yy, vis[MAXN];
pii v[MAXN];

void dfs(int u){
	vis[u]=1;
	x=min(x, v[u].ff); xx=max(xx, v[u].ff);
	y=min(y, v[u].ss); yy=max(yy, v[u].ss);
	for(auto k : adj[u]){
		if(vis[k]==0){
			dfs(k);
		}
	}
}

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("fenceplan");

	int n, m; cin >> n >> m;
	
	for(int i=1; i<=n; i++) cin >> v[i].ff >> v[i].ss;
	for(int i=0; i<m; i++){
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int ans=INF;
	for(int i=1; i<=n; i++){
		if(vis[i]==0){
			x=INF; y=INF;
			xx=-1; yy=-1;
			dfs(i);
			ans=min(ans, 2*(xx-x)+2*(yy-y));
		}
	}
	
	cout << ans;
	return 0;
}
