#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN=110;
const int col=4;
vector<int>dif[MAXN];

int main(){
	setIO("revegetate");

	int n, m; cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b;
		dif[a].push_back(b);
		dif[b].push_back(a);
	}
	
	vector<int>ans(n+1);
	for(int i=1; i<=n; i++){
		vector<int>bad(col+1);
		for(auto x : dif[i]) if(x<i) bad[ans[x]]++;
		
		for(int j=1; j<=col; j++){
			if(bad[j]==0){
				ans[i]=j;
				break;
			}
		}
	}
	
	for(int i=1; i<=n; i++) cout << ans[i];
	return 0;
}
