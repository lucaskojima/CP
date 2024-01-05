#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
typedef long long ll;
const ll INFL=(1ll << 60);
const int INF=(1 << 30);

const int MAXN=3e4+10;
int pai[MAXN], prof[MAXN], sz[MAXN];

int find(int v){
	if(pai[v]==v) return v;
	return pai[v]=find(pai[v]);
}

void une(int a, int b){
	a=find(a); b=find(b);
	if(a==b) return;
	if(prof[a]>prof[b]){
		pai[b]=a;
		sz[a]+=sz[b];
		return;
	}
	pai[a]=b;
	sz[b]+=sz[a];
	if(prof[a]==prof[b]) prof[b]++;
}

void solve(){
	int n, m; cin >> n >> m;
	for(int i=1; i<=n; i++){
		pai[i]=i;
		sz[i]=1;
	}
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b;
		une(a, b);
	}
	int ans=0;
	for(int i=1; i<=n; i++){
		int k=find(i);
		ans=max(ans, sz[k]);
	}
	cout << ans << endl;
	
	//clear
	for(int i=0; i<=n; i++){
		pai[i]=0; prof[i]=0; sz[i]=0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

