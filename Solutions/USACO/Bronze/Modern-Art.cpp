#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN=15;
int n, marc[MAXN], ap[MAXN], ma[MAXN][MAXN];

void f(int x){
	int min_i=1e9, max_i=0;
	int min_j=1e9, max_j=0;
	bool ok=false;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(ma[i][j]==x){
				ok=true;
				min_i=min(min_i, i);
				max_i=max(max_i, i);
				min_j=min(min_j, j);
				max_j=max(max_j, j);
			}
		}
	}
	
	if(ok){
		for(int i=min_i; i<=max_i; i++){
			for(int j=min_j; j<=max_j; j++){
				if(ma[i][j]!=x) marc[ma[i][j]]++;
			}
		}
	}
}

int main(){
	setIO("art");

	cin >> n;
	for(int i=0; i<n; i++){
		string aux; cin >> aux;
		for(int j=0; j<n; j++){
			ma[i][j]=aux[j]-'0';
			ap[ma[i][j]]++;
		}
	}
	
	for(int i=1; i<=9; i++) f(i);
	
	int ans=0;
	for(int i=1; i<=9; i++){
		if(marc[i]==0 && ap[i]!=0) ans++;
	}
	
	cout << ans << '\n';
	return 0;
}
