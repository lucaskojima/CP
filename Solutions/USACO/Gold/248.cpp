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

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN = 250;
int n, v[MAXN], dp[MAXN][MAXN];

int calc(int i, int j){
	if(i==j) return dp[i][j]=v[i];
	if(dp[i][j]!=-1) return dp[i][j];

	dp[i][j]=0;
	for(int u=i; u<j; u++){
		int rng1=calc(i, u);
		int rng2=calc(u+1, j);
		if(rng1==rng2) dp[i][j]=max(dp[i][j], rng1+1);
	}
	
	return dp[i][j];
}

int main(){
	setIO("248");
	
	cin >> n;
	for(int i=1; i<=n; i++) cin >> v[i];
	
	memset(dp, -1, sizeof(dp));
	calc(1, n);
	
	int ans=0;
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			ans=max(ans, dp[i][j]);
		}
	}
	
	cout << ans << '\n';
	return 0;
}
