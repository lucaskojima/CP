#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN=21;

int main(){
	setIO("gymnastics");
	
	int k, n; cin >> k >> n;
	vector<vector<int>>pos(n+1);
	
	for(int i=0; i<k; i++){
		for(int j=0; j<n; j++){
			int a; cin >> a;
			pos[a].push_back(j);
		}
	}
	
	int ans=0;
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			int a=i, b=j;
			bool menor=false, maior=false;
			for(int x=0; x<k; x++){
				if(pos[a][x]<pos[b][x]) menor=true;
				if(pos[a][x]>pos[b][x]) maior=true;
			}
			
			if((menor && !maior) || (!menor && maior)) ans++;
		}
	}
	
	cout << ans;
	return 0;
}
