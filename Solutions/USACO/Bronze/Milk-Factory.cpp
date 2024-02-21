#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN=110;
int marc[MAXN];

int main(){
	setIO("factory");

	int n; cin >> n;
	for(int i=0; i<n-1; i++){
		int a, b; cin >> a >> b;
		marc[a]++;
	}
	
	int ans=0; bool ok=true;
	for(int i=1; i<=n; i++){
		if(marc[i]==0){
			if(ans==0) ans=i;
			else ok=false;
		}
	}
	
	if(ans!=0 && ok) cout << ans << '\n';
	else cout << "-1\n";
	return 0;
}
