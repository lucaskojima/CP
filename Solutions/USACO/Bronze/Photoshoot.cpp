#include "bits/stdc++.h"
using namespace std;

int rev(int x){
	if(x==0) return 1;
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	string s; cin >> s;
	
	vector<int>bin;
	for(int i=0; i<n; i+=2){
		if(s[i]!=s[i+1]){
			if(s[i]=='G' && s[i+1]=='H') bin.push_back(1);
			if(s[i]=='H' && s[i+1]=='G') bin.push_back(0);
		}
	}
	
	int tg=1, ans=0;
	for(int i=bin.size()-1; i>=0; i--){
		if(bin[i]==tg){
			ans++;
			tg=rev(tg);
		}
	}
	
	cout << ans << '\n';
	return 0;
}
