#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

set<int>ans;

void bt(int idx, vector<int>va, int a, vector<int>vb, int b){
	if(idx==4){
		ans.insert(a);
		return;
	}
	
	if(idx%2==0){
		for(int i=0; i<(int)va.size(); i++){
			int k=va[i];
			vector<int>ka=va; ka.erase(ka.begin()+i);
			vector<int>kb=vb; kb.push_back(k);
			bt(idx+1, ka, a-k, kb, b+k);
		}
	} else {
		for(int i=0; i<(int)vb.size(); i++){
			int k=vb[i];
			vector<int>ka=va; ka.push_back(k);
			vector<int>kb=vb; kb.erase(kb.begin()+i);
			bt(idx+1, ka, a+k, kb, b-k);
		}
	}
}

int main(){
	setIO("backforth");
	
	vector<int>va(10); for(auto &x : va) cin >> x;
	vector<int>vb(10); for(auto &x : vb) cin >> x;
	
	bt(0, va, 1000, vb, 1000);
	
	cout << ans.size() << '\n';
	return 0;
}
