#include "bits/stdc++.h"
using namespace std;

const int MAXN=1010;
int marc[MAXN];

void usaco_io(string problemcode = "") {
  if (problemcode != "") {
    string input_file = problemcode + ".in";
    string output_file = problemcode + ".out";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
  }
}

int main(){
	usaco_io("blist");
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	for(int i=0; i<n; i++){
		int s, t, b; cin >> s >> t >> b;
		for(int j=s; j<=t; j++) marc[j]+=b;
	}
	int ans=0;
	for(int i=0; i<1000; i++){
		ans=max(ans, marc[i]);
	}
	cout << ans;
	return 0;
}
