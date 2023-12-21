#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("cowsignal");

	int n, m, k; cin >> n >> m >> k;
	char ma[n][m], ans[n*k][m*k];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> ma[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			for(int ki=i*k; ki<i*k+k; ki++){
				for(int kj=j*k; kj<j*k+k; kj++){
					ans[ki][kj]=ma[i][j];
				}
			}
		}
	}
	for(int i=0; i<n*k; i++){
		for(int j=0; j<m*k; j++){
			cout << ans[i][j];
		}
		cout << '\n';
	}
	return 0;
}
