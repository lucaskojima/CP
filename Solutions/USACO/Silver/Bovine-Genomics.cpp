// que problema merda...

#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int f(char c){
	if(c=='A') return 1;
	if(c=='C') return 2;
	if(c=='G') return 3;
	return 4;
}

int main(){
	setIO("cownomics");

	int n, m; cin >> n >> m;
	
	int s[n][m], p[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			char c; cin >> c;
			s[i][j]=f(c);
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			char c; cin >> c;
			p[i][j]=f(c);
		}
	}
	
	int ans=0;
	for(int a=0; a<m; a++){
		for(int b=a+1; b<m; b++){
			for(int c=b+1; c<m; c++){
				bool ok=true;
				set<vector<int>>st;
				for(int k=0; k<n; k++){
					vector<int>v={s[k][a], s[k][b], s[k][c]};
					st.insert(v);
				}
				for(int k=0; k<n; k++){
					vector<int>v={p[k][a], p[k][b], p[k][c]};
					if(st.find(v)!=st.end()) ok=false;
				}
				
				if(ok) ans++;
			}
		}
	}
	
	cout << ans;
	return 0;
}
