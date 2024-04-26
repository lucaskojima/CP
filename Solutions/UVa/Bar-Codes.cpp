#include "bits/stdc++.h"
using namespace std;

#define int long long

template<typename T>
using matrix = vector<vector<T>>;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, b, s; 
	while(cin >> n >> b >> s){
		matrix<vector<int>>dp(n+1, matrix<int>(b+1, vector<int>(s+1)));
		dp[1][1][1]=1;
		
		for(int i=2; i<=n; i++){
			for(int j=1; j<=b; j++){
				for(int k=1; k<=s; k++){
					//th-bar -> th-bar-1
					dp[i][j][1]+=dp[i-1][j-1][k];
				}
			}
			for(int j=1; j<=b; j++){
				for(int k=2; k<=s; k++){
					//th-bar -> th-bar
					dp[i][j][k]=dp[i-1][j][k-1];
				}
			}
		}
		
		int ans=0;
		for(int i=1; i<=s; i++) ans+=dp[n][b][i];
		
		cout << ans << '\n';
	}
	return 0;
}
