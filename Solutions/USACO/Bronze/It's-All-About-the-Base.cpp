#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int maxn=15000;

int val(string s, int b){
	return (s[0]-'0')*b*b+(s[1]-'0')*b+(s[2]-'0');
}

void solve(){
	string sx, sy; cin >> sx >> sy;
	
	int x=10, y=10;
	while(x<=maxn && y<=maxn){
		int num_x=val(sx, x);
		int num_y=val(sy, y);
		
		if(num_x<num_y){
			x++;
		} else if(num_x>num_y){
			y++;
		} else {
			cout << x << " " << y << '\n';
			break;
		}
	}
}

int main(){
	setIO("whatbase");

	int t; cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
