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

int vis[MAXN][MAXN], cow[MAXN][MAXN];
map<pii, vector<pii>>block;
int n, k, r, currc=0;

int dx[]={-1, 0, 1, 0};
int dy[]={0, -1, 0, 1};

bool val(int x, int y){
	return x>=1 && x<=n && y>=1 && y<=n && vis[x][y]==0;
}

void dfs(int x, int y){
	vis[x][y]=1;
	currc+=cow[x][y];
	
	set<pii>st;
	for(auto x : block[{x, y}]) st.insert(x);
	
	for(int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(val(nx, ny) && (st.empty() || st.find({nx, ny})==st.end())){
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
	setIO("countcross");

	cin >> n >> k >> r;
	for(int i=0; i<r; i++){
		int a, b, c, d; cin >> a >> b >> c >> d;
		block[{a, b}].push_back({c, d});
		block[{c, d}].push_back({a, b});
	}
	
	for(int i=0; i<k; i++){
		int a, b; cin >> a >> b;
		cow[a][b]++;
	}
	
	vector<int>v;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(vis[i][j]==0){
				dfs(i, j);
				if(currc>0) v.push_back(currc);
				currc=0;
			}
		}
	}
	
	int ans=0;
	for(int i=0; i<sz(v); i++){
		for(int j=i+1; j<sz(v); j++){
			ans+=v[i]*v[j];
		}
	}
	
	cout << ans << '\n';
	return 0;
}
