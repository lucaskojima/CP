#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

char ma[3][3];
set<set<char>>ans[4];

void calc(vector<pair<int, int>>vp){
	set<char>st;
	for(auto x : vp){
		st.insert(ma[x.first][x.second]);
	}
	ans[st.size()].insert(st);
}

int main(){
	setIO("tttt");

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin >> ma[i][j];
		}
	}
	
	for(int i=0; i<3; i++) calc({{i, 0}, {i, 1}, {i, 2}});
	for(int i=0; i<3; i++) calc({{0, i}, {1, i}, {2, i}});
	calc({{0, 0}, {1, 1}, {2, 2}});
	calc({{0, 2}, {1, 1}, {2, 0}});
	
	cout << ans[1].size() << '\n';
	cout << ans[2].size() << '\n';
	
	return 0;
}
