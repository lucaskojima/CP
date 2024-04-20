#include "bits/stdc++.h"
using namespace std;

template<typename T>
using matrix = vector<vector<T>>;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n){
        if(n==0) break;

        matrix<int>dp(n+1, vector<int>(3));
        dp[1][0]=1; dp[1][1]=1; dp[1][2]=0;

        for(int i=2; i<=n; i++){
            dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
            dp[i][1]=dp[i-1][0];
            dp[i][2]=dp[i-1][1];
        }

        cout << (1<<n)-(dp[n][0]+dp[n][1]+dp[n][2]) << '\n';
    }

    return 0;
}
