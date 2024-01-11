#include "bits/stdc++.h"
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	
	int par=0, imp=0;
	for(int i=0; i<n; i++){
		int a; cin >> a;
		if(a%2==0) par++;
		if(a%2!=0) imp++;
	}
	
	if(par==imp){
		cout << par+imp;
	} else if(par>imp){
		cout << 2*imp+1;
	} else if(par<imp){
		while(imp>par){
			imp-=2;
			par++;
		}
		if(par>imp+1) par=imp+1;
		cout << par+imp;
	}
	
	return 0;
}
