#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("hps");

	int n; cin >> n;
    
    vector<int>h(n+1), p(n+1), s(n+1);
    for(int i=1; i<=n; i++){
        char c; cin >> c;
        if(c=='H') h[i]++;
        if(c=='P') p[i]++;
        if(c=='S') s[i]++;
    }
    
    for(int i=1; i<=n; i++) h[i]+=h[i-1];
    for(int i=1; i<=n; i++) p[i]+=p[i-1];
    for(int i=1; i<=n; i++) s[i]+=s[i-1];
    
    int ans=0;
    for(int i=1; i<=n; i++){
        ans=max(ans, max({h[i], p[i], s[i]})+max({h[n]-h[i], p[n]-p[i], s[n]-s[i]}));
    }
    
    cout << ans;
	return 0;
}
