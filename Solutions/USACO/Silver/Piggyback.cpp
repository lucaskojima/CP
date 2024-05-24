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
const int MAXN = 4e4+10;

vector<int>adj[MAXN];
int vis[MAXN], distb[MAXN], diste[MAXN], distn[MAXN];

void bfs(int s, int seed){
	queue<int>q; q.push(s);
	vis[s]=1;
	if(seed==1) distb[s]=0;
	if(seed==2) diste[s]=0;
	if(seed==3) distn[s]=0;
	
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(auto k : adj[x]){
			if(vis[k]==1) continue;
			q.push(k);
			vis[k]=1;
			if(seed==1) distb[k]=distb[x]+1;
			if(seed==2) diste[k]=diste[x]+1;
			if(seed==3) distn[k]=distn[x]+1;
		}
	}
}

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("piggyback");

	int b, e, p, n, m; cin >> b >> e >> p >> n >> m;
	
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	bfs(1, 1); for(int i=1; i<=n; i++) vis[i]=0;
	bfs(2, 2); for(int i=1; i<=n; i++) vis[i]=0;
	bfs(n, 3); for(int i=1; i<=n; i++) vis[i]=0;
	
	int ans=(distb[n]*b)+(diste[n]*e);
	for(int i=1; i<=n; i++){
		int d=(distb[i]*b)+(diste[i]*e)+(distn[i]*p);
		ans=min(ans, d);
	}
	
	cout << ans;
	return 0;
}
