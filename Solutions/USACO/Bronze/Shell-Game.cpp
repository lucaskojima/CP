#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("shell");

	int n; cin >> n;
	
	vector<int>pos(3);
	for(int i=0; i<3; i++) pos[i]=i;
	
	vector<int>count(3);
	for(int i=0; i<n; i++){
		int a, b, g; cin >> a >> b >> g;
		a--; b--; g--;
		swap(pos[a], pos[b]);
		count[pos[g]]++;
	}
	
	cout << max({count[0], count[1], count[2]});
	return 0;
}
