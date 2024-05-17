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

char ma[MAXN][MAXN];
int n, vis[MAXN][MAXN];
int curra=0, currp=0;

void dfs(int x, int y){
	if(x<1 || x>n || y<1 || y>n){
		currp++;
		return;
	}
	if(vis[x][y]==1) return;
	if(ma[x][y]=='.'){
		currp++;
		return;
	}
	
	vis[x][y]=1;
	if(ma[x][y]=='#') curra++;
	
	dfs(x+1, y);
	dfs(x-1, y);
	dfs(x, y+1);
	dfs(x, y-1);
}

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}


int main(){
	setIO("perimeter");

	cin >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> ma[i][j];
		}
	}
	
	int a=0, p=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(ma[i][j]=='#' && vis[i][j]==0){
				dfs(i, j);
				if(curra>a){a=curra; p=currp;}
				if(curra==a){p=min(p, currp);}
				curra=0; currp=0;
			}
		}
	}
	
	cout << a << " " << p << '\n';
	return 0;
}
