#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second

void usaco_io(string problemcode = "") {
  if (problemcode != "") {
    string input_file = problemcode + ".in";
    string output_file = problemcode + ".out";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
  }
}

int main(){
	usaco_io("shell");
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	vector<pair<int, int>>swp;
	vector<int>v;
	for(int i=0; i<n; i++){
		int a, b, g; cin >> a >> b >> g;
		swp.push_back({a, b});
		v.push_back(g);
	}
	//ta no 1
	int k=1, ans1=0;
	for(int i=0; i<n; i++){
		if(swp[i].ff==k) k=swp[i].ss;
		else if(swp[i].ss==k) k=swp[i].ff;
		if(v[i]==k) ans1++;
	}
	
	//ta no 2
	k=2;
	int ans2=0;
	for(int i=0; i<n; i++){
		if(swp[i].ff==k) k=swp[i].ss;
		else if(swp[i].ss==k) k=swp[i].ff;
		if(v[i]==k) ans2++;
	}
	
	//ta no 3
	k=3;
	int ans3=0;
	for(int i=0; i<n; i++){
		if(swp[i].ff==k) k=swp[i].ss;
		else if(swp[i].ss==k) k=swp[i].ff;
		if(v[i]==k) ans3++;
	}
	
	cout << max({ans1, ans2, ans3});
	return 0;
}

//swap(a, b);
//swap(posicao[swp[i].ff], posicao[swp[i].ss]);
