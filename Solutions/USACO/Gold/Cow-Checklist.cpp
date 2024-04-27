#include "bits/stdc++.h"
using namespace std;

#define int long long
#define ff first
#define ss second

template<typename T>
using matrix = vector<vector<T>>;
using pii = pair<int, int>;

const int INF=(1LL<<60);

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int32_t main(){
	setIO("checklist");

	int h, g; cin >> h >> g;
	vector<pii>hol(h+1); for(int i=1; i<=h; i++) cin >> hol[i].ff >> hol[i].ss;
	vector<pii>gue(g+1); for(int i=1; i<=g; i++) cin >> gue[i].ff >> gue[i].ss;
	
	matrix<vector<int>>dp(h+1, matrix<int>(g+1, vector<int>(2, INF)));
	dp[1][0][0]=0;
	
	auto d=[&](pii a, pii b){
		int dx=(a.ff-b.ff)*(a.ff-b.ff);
		int dy=(a.ss-b.ss)*(a.ss-b.ss);
		return dx+dy;
	};
	
	for(int i=1; i<=h; i++){
		for(int j=0; j<=g; j++){
			if(i==1 && j==0) continue;
			
			dp[i][j][0]=min(dp[i-1][j][0]+d(hol[i], hol[i-1]), dp[i-1][j][1]+d(hol[i], gue[j]));
			if(j==0) continue;
			dp[i][j][1]=min(dp[i][j-1][0]+d(gue[j], hol[i]), dp[i][j-1][1]+d(gue[j], gue[j-1]));
		}
	}
	
	cout << dp[h][g][0] << '\n';
	return 0;
}

// H -> 0   G -> 1
// dp[h][g][0] -> number of H, number of G, finish with H
// dp[h][g][1] -> number of H, number of G, finish with G
