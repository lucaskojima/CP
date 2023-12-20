#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second

typedef long long ll;

void usaco_io(string problemcode = "") {
  if (problemcode != "") {
    string input_file = problemcode + ".in";
    string output_file = problemcode + ".out";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
  }
}

int main(){
	usaco_io("mixmilk");
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<pair<ll, ll>>v(3);
	for(int i=0; i<3; i++){
		cin >> v[i].ff >> v[i].ss;
	}
	
	int k=0;
	for(int i=0; i<100; i++){
		int l=(k%3), r=((k+1)%3);
		int dif=min(v[r].ff, v[l].ss+v[r].ss)-v[r].ss;
		v[l].ss-=dif;
		v[r].ss+=dif;
		k++;
	}
	
	for(int i=0; i<3; i++){
		cout << v[i].ss << '\n';
	}
	
	return 0;
}
