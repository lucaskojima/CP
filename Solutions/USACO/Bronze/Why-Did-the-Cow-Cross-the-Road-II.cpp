#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
pair<int, int> marc[26];

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("circlecross");

	string s; cin >> s;
	for(int i=0; i<s.size(); i++){
		if(marc[s[i]-'A'].ff==0){
			marc[s[i]-'A'].ff=i+1;
		} else {
			marc[s[i]-'A'].ss=i+1;
		}
	}
	
	int ans=0;
	for(int i=0; i<26; i++){
		for(int j=0; j<26; j++){
			if(marc[i].ff<marc[j].ff && marc[j].ff<marc[i].ss && marc[i].ss<marc[j].ss){
				ans++;
			}
		}
	}
	
	cout << ans;
	return 0;
}
