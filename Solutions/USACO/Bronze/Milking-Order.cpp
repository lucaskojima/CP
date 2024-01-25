#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int n, m, k;

bool ok(vector<int>hier, vector<int>fixo){
	vector<int>idx(n+1);
	for(int i=1; i<=n; i++){
		if(fixo[i]!=0) idx[fixo[i]]=i;
	}
	
	int f=1;
	for(int i=1; i<=m; i++){
		if(idx[hier[i]]!=0){
			if(f>idx[hier[i]]) return false;
			
			f=idx[hier[i]]+1;
		} else {
			while(f<=n && fixo[f]!=0) f++;
			if(f==n+1) return false;
			
			fixo[f]=hier[i];
			idx[hier[i]]=f;
			f++;
		}
	}
	return true;
}

int main(){
	setIO("milkorder");

	cin >> n >> m >> k;
	
	vector<int>hier(m+1);
	for(int i=1; i<=m; i++){
		cin >> hier[i];
	}
	
	vector<int>fixo(n+1);
	for(int i=0; i<k; i++){
		int a, b; cin >> a >> b;
		fixo[b]=a;
		
		if(a==1){
			cout << b << '\n';
			return 0;
		}
	}
	
	for(int i=1; i<=n; i++){
		if(fixo[i]==0){
			fixo[i]=1;
			if(ok(hier, fixo)){
				cout << i << '\n';
				return 0;
			}
			fixo[i]=0;
		}
	}
	return 0;
}
