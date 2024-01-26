#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int MAXN=110;
int n, v[MAXN];

bool ok(int val, int idx){
	idx--;
	while(val--){
		if(idx<0) return false;
		if(v[idx]!=val && v[idx]!=-1) return false;
		idx--;
	}
	return true;
}

void fix(int val, int idx){
	idx--;
	while(val--){
		v[idx]=val;
		idx--;
	}
}

int main(){
	setIO("taming");

	cin >> n;
	for(int i=0; i<n; i++) cin >> v[i];
	
	v[0]=0;
	for(int i=0; i<n; i++){
		if(v[i]!=-1){
			if(ok(v[i], i)) fix(v[i], i);
			else {
				cout << "-1";
				return 0;
			}
		}
	}
	
	int mi=0, ma=0;
	for(int i=0; i<n; i++){
		if(v[i]==0){
			mi++;
			ma++;
		}
		if(v[i]==-1){
			ma++;
		}
	}
	
	cout << mi << " " << ma << '\n';
	
	return 0;
}
