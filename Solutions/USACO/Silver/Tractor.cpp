#include "bits/stdc++.h"
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const char nl = '\n';
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

struct DSU{
	vector<int>pai, rank, size;
	DSU(int n) : pai(n+1), rank(n+1), size(n+1, 1){
		for(int i=1; i<=n; i++) pai[i]=i;
	}

	int find(int v){
		return pai[v]==v ? v : pai[v]=find(pai[v]);
	}
	void une(int a, int b){
		a=find(a), b=find(b);
		if(a==b) return;
		if(rank[a]>rank[b]) swap(a, b);

		pai[a]=b;
		size[b]+=size[a];
		if(rank[a]==rank[b]) rank[b]++;
	}
};

int main(){
	setIO("tractor");

	int n; cin >> n;
	
	auto ceil = [&](int a, int b) -> int{
		return (a+b-1)/b;
	};
	int k=ceil(n*n, 2);

	vector<vector<int>>ma(n+1, vector<int>(n+1));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin >> ma[i][j];
	
	vector<int>dx={-1, 1, 0, 0};
	vector<int>dy={0, 0, -1, 1};


	auto ok = [&](int x) -> bool{

		auto val = [&](int i, int j) -> bool{
			return i>=1 && i<=n && j>=1 && j<=n;
		};
		auto id = [&](int i, int j) -> int{
			return n*(i-1)+j;
		};

		DSU dsu(n*n);

		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				for(int d=0; d<4; d++){
					int ni=i+dx[d], nj=j+dy[d];
					if(val(ni, nj) && abs(ma[i][j]-ma[ni][nj])<=x){
						dsu.une(id(i, j), id(ni, nj));
					}
				}
		
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				if(dsu.size[dsu.find(id(i, j))]>=k) return true;

		return false;
	};

	int l=-1;    // bad
	int r=1e9+1; // good
	while(r>l+1){
		int m=(l+r)/2;
		if(ok(m)) r=m;
		else l=m;
	}

	cout << r << nl;
	return 0;
}
