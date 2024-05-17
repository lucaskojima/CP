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
const int MAXN = 3e3+10;

int ma[MAXN][MAXN], vis[MAXN][MAXN];
int mnx=INF, mny=INF;
int mxx=-INF, mxy=-INF;

int dx[]={-1, 0, 1, 0};
int dy[]={0, -1, 0, 1};

bool val(int x, int y){
    return x>=mnx && x<=mxx && y>=mny && y<=mxy && vis[x][y]==0 && ma[x][y]==0;
}

void dfs(int x, int y){
	vis[x][y]=1;
	for(int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(val(nx, ny)){
			dfs(nx, ny);
		}
	}
}

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("gates");
	
	int n; cin >> n;
	string s; cin >> s;
	
	pii pos={1010, 1010};
	ma[pos.ff][pos.ss]=1;
	
	for(int i=0; i<n; i++){
		if(s[i]=='N'){
			pos.ff--; ma[pos.ff][pos.ss]=1;
			pos.ff--; ma[pos.ff][pos.ss]=1;
		}
		if(s[i]=='S'){
			pos.ff++; ma[pos.ff][pos.ss]=1;
			pos.ff++; ma[pos.ff][pos.ss]=1;
		}
		if(s[i]=='E'){
			pos.ss++; ma[pos.ff][pos.ss]=1;
			pos.ss++; ma[pos.ff][pos.ss]=1;
		}
		if(s[i]=='W'){
			pos.ss--; ma[pos.ff][pos.ss]=1;
			pos.ss--; ma[pos.ff][pos.ss]=1;
		}
		mxx=max(mxx, pos.ff);
		mnx=min(mnx, pos.ff);
		mxy=max(mxy, pos.ss);
		mny=min(mny, pos.ss);
	}
	
	mxx++; mxy++;
	mnx--; mny--;
	
	int ans=0;
	for(int i=mnx; i<=mxx; i++){
		for(int j=mny; j<=mxy; j++){
			if(vis[i][j]==0 && ma[i][j]==0){
				dfs(i, j);
				ans++;
			}
		}
	}
	
	cout << ans-1;
	return 0;
}
