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

vector<pii>adj[MAXN];
int vis[MAXN], comp[MAXN];

void dfs(int x, int w, int c){
	vis[x]=1; comp[x]=c;
	for(auto k : adj[x]){
		if(vis[k.ff]==0 && k.ss>=w){
			dfs(k.ff, w, c);
		}
	}
}

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("wormsort");
	
	int n, m; cin >> n >> m;
	
	vector<int>pos(n+1);
	for(int i=1; i<=n; i++) cin >> pos[i];
	
	for(int i=0; i<m; i++){
		int a, b, w; cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}
	
	auto ok=[&](int x){
		memset(vis, 0, sizeof(vis));
		memset(comp, 0, sizeof(comp));
		
		int k=1;
		for(int i=1; i<=n; i++){
			if(vis[i]==0) dfs(i, x, k), k++;
		}
		
		bool ok=true;
		for(int i=1; i<=n; i++){
			if(comp[i]!=comp[pos[i]]) ok=false;
		}
		return ok;
	};
	
	int l=1;     // l is good
	int r=1e9+1; // r is bad
	while(r>l+1){
		int m=(l+r)/2;
		if(ok(m)) l=m;
		else r=m;
	}
	
	cout << (l==1e9 ? -1 : l) << '\n';
	return 0;
}
