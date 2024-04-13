#include "bits/stdc++.h"
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	while(getline(cin, a)){
		getline(cin, b);
		
		int n=(int)a.size();
		int m=(int)b.size();
		
		vector<vector<int>>dp(n+1, vector<int>(m+1));
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
		
		cout << dp[n][m] << '\n';
	}
	return 0;
}
