#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("lostcow");

	int ini, fim; cin >> ini >> fim;
	
	if(ini==fim){
		cout << "0";
		return 0;
	} else if(ini<fim){
		int pos=ini, k=1, ans=0;
		while(pos<fim){
			ans+=abs(pos-(ini+k));
			pos=ini+k;
			k*=-2;
		}
		ans-=pos-fim;
		
		cout << ans;
		return 0;
	} else if(ini>fim){
		int pos=ini, k=1, ans=0;
		while(pos>fim){
			ans+=abs(pos-(ini+k));
			pos=ini+k;
			k*=-2;
		}
		ans-=fim-pos;
		
		cout << ans;
		return 0;
	}
}
