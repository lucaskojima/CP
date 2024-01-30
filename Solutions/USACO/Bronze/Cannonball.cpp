#include "bits/stdc++.h"
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s; cin >> n >> s;
	
	vector<int>a(n+1), b(n+1);
	for(int i=1; i<=n; i++){
		cin >> a[i] >> b[i];
	}
	
	int pos=s, pw=1, dir=1, ans=0;
	vector<int>vis(n+1, 0), marc(n+1, 0);
	
	while(pos>=1 && pos<=n){
		int q=a[pos], v=b[pos];
		vis[pos]++;
		
		if(q==0){
			pw+=v;
			dir*=-1;
			
			if(v==0 && vis[pos]>=10) break;
		} else {
			if(pw>=v && marc[pos]==0){
				marc[pos]=1;
				ans++;
			}
		}
		
		pos+=(pw*dir);
	}
	
	cout << ans;
	return 0;
}
