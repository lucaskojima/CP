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
const int MAXN = 110;

vector<pii>marc[MAXN][MAXN];
int n, vis[MAXN][MAXN];
set<pii>key;

int dx[]={-1, 0, 1, 0};
int dy[]={0, -1, 0, 1};

bool val(int x, int y){
    return x>=1 && x<=n && y>=1 && y<=n && vis[x][y]!=1;
}

void dfs(int x, int y){
    for(auto [i, j] : marc[x][y]){
        if(vis[i][j]==2) dfs(i, j);
        else key.insert({i, j});
    }
    vis[x][y]=1;
    for(int i=0; i<4; i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(val(nx, ny)){
            if(key.find({nx, ny})!=key.end()){
                dfs(nx, ny);
            } else vis[nx][ny]=2;
        }
    }
}

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("lightson");

	int m; cin >> n >> m;
	
	for(int i=0; i<m; i++){
	    int x, y, a, b; cin >> x >> y >> a >> b;
	    marc[x][y].push_back({a, b});
	}
	
	dfs(1, 1);
	
	int ans=0;
	for(int i=1; i<=n; i++){
	    for(int j=1; j<=n; j++){
	        if(vis[i][j]==1) ans++;
	    }
	}
	
	cout << ans << '\n';
	return 0;
}
