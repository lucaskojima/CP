#include "bits/stdc++.h"
using namespace std;

#define int long long
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
const int MAXN = 550;

int ma[MAXN][MAXN], way[MAXN][MAXN], vis[MAXN][MAXN];
int n, m;

int dx[]={-1, 0, 1, 0};
int dy[]={0, -1, 0, 1};

bool val(int x, int y){
	return x>=1 && x<=n && y>=1 && y<=m && vis[x][y]==0;
}

void dfs(int x, int y, int d){
	vis[x][y]=1;
	for(int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(val(nx, ny) && abs(ma[x][y]-ma[nx][ny])<=d){
			dfs(nx, ny, d);
		}
	}
}

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main(){
	setIO("ccski");
	
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> ma[i][j];
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> way[i][j];
		}
	}
	
	auto ok=[&](int x){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(way[i][j]==1){
					dfs(i, j, x);
					goto exit;
				}
			}
		}
		exit:
		
		bool ok=true;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(way[i][j]==1 && vis[i][j]==0) ok=false;
			}
		}
		
		memset(vis, 0, sizeof(vis));
		return ok;
	};
	
	int l=-1; // l is bad
	int r=1;  // r is good
	while(!ok(r)) r*=2;
	
	while(r>l+1){
		int m=(l+r)/2;
		if(ok(m)) r=m;
		else l=m;
	}
	
	cout << r << '\n';
	return 0;
}
