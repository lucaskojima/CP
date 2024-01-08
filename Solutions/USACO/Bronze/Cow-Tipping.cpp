#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("cowtip");

	int n; cin >> n;
	char ma[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			char c; cin >> c;
			ma[i][j]=c;
		}
	}
	
	int ans=0;
	for(int i=n-1; i>=0; i--){
		for(int j=n-1; j>=0; j--){
			if(ma[i][j]=='1'){
				ans++;
				
				for(int a=0; a<=i; a++){
					for(int b=0; b<=j; b++){
						if(ma[a][b]=='0'){
							ma[a][b]='1';
						} else {
							ma[a][b]='0';
						}
					}
				}
			}
		}
	}
	
	cout << ans;
	return 0;
}
