#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
    ios::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int MAXN=1e5+10;
const int MAXK=25;
int dp[MAXN][MAXK][3];

int main(){
    setIO("hps");
    int n, x; cin >> n >> x;

    vector<int>v;
    for(int i=0; i<n; i++){
        char c; cin >> c;
        if(c=='H') v.push_back(0);
        if(c=='P') v.push_back(1);
        if(c=='S') v.push_back(2);
    }

    auto f=[](int a, int b){
        if(a==0 && b==2) return 1;
        if(a==1 && b==0) return 1;
        if(a==2 && b==1) return 1;
        return 0;
    };

    for(int i=0; i<3; i++){
        dp[1][0][i]=f(i, v[0]);
    }

    for(int i=2; i<=n; i++){
        for(int j=0; j<=x; j++){
            for(int k=0; k<3; k++){
                int add=f(k, v[i-1]);
                if(j==0) dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k]+add);
                else dp[i][j][k]=max({dp[i-1][j-1][0]+add, dp[i-1][j-1][1]+add, dp[i-1][j-1][2]+add, dp[i-1][j][k]+add});
            }
        }
    }

    int ans=0;
    for(int i=0; i<=x; i++){
        for(int j=0; j<3; j++){
            ans=max(ans, dp[n][i][j]);
        }
    }

    cout << ans << '\n';
    return 0;
}
