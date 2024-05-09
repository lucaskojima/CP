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
const int MAXN = 1e3+10;

vector<int>adj[MAXN];
int node=0, vis[MAXN];

void dfs(int x){
	vis[x]=1; node++;
	for(auto k : adj[x]){
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
	setIO("moocast");
	
	int n; cin >> n;
	vector<pii>v(n); for(auto &[x, y] : v) cin >> x >> y;
	
	auto ok=[&](int x){
		for(int i=0; i<n; i++) adj[i].clear(), vis[i]=0;
		node=0;
		
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				int dx=v[i].ff-v[j].ff;
				int dy=v[i].ss-v[j].ss;
				if((dx*dx)+(dy*dy)<=x){
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		
		dfs(0);
		return node==n;
	};
	
	int l=0; // l is bad
	int r=1; // r is good
	while(!ok(r)) r*=2;
	
	while(r>l+1){
		int m=(l+r)/2;
		if(ok(m)) r=m;
		else l=m;
	}
	
	cout << r << '\n';
	return 0;
}
