#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

#define int long long
#define ff first
#define ss second
template<typename T>
using matrix = vector<vector<T>>;
using pii = pair<int, int>;

int32_t main(){
	setIO("radio");

	int n, m; cin >> n >> m;
	int fx, fy; cin >> fx >> fy;
	int bx, by; cin >> bx >> by;
	
	vector<pii>f(n+1); f[0]={fx, fy};
	for(int i=1; i<=n; i++){
		char c; cin >> c;
		if(c=='N') f[i]={f[i-1].ff, f[i-1].ss+1};
		if(c=='E') f[i]={f[i-1].ff+1, f[i-1].ss};
		if(c=='S') f[i]={f[i-1].ff, f[i-1].ss-1};
		if(c=='W') f[i]={f[i-1].ff-1, f[i-1].ss};
	}
	
	vector<pii>b(m+1); b[0]={bx, by};
	for(int i=1; i<=m; i++){
		char c; cin >> c;
		if(c=='N') b[i]={b[i-1].ff, b[i-1].ss+1};
		if(c=='E') b[i]={b[i-1].ff+1, b[i-1].ss};
		if(c=='S') b[i]={b[i-1].ff, b[i-1].ss-1};
		if(c=='W') b[i]={b[i-1].ff-1, b[i-1].ss};
	}
	
	auto dist=[&](pii a, pii b){
		return (a.ff-b.ff)*(a.ff-b.ff)+(a.ss-b.ss)*(a.ss-b.ss);
	};
	
	matrix<int>dp(n+1, vector<int>(m+1, 1e18)); dp[0][0]=0;
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			if(i==0 && j==0) continue;
			if(i==0) dp[i][j]=dp[i][j-1]+dist(f[i], b[j]);
			if(j==0) dp[i][j]=dp[i-1][j]+dist(f[i], b[j]);
			if(i!=0 && j!=0) dp[i][j]=min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+dist(f[i], b[j]);
		}
	}
	
	cout << dp[n][m];
	return 0;
}
