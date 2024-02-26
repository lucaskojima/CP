#include "bits/stdc++.h"
using namespace std;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

#define int long long

int32_t main(){
	setIO("stacking");
    
    int n, q; cin >> n >> q;
    
    vector<int>v(n+1);
    
    for(int i=0; i<q; i++){
        int a, b; cin >> a >> b;
        v[a]++;
        v[b+1]--;
    }
    
    v[0]=0;
    for(int i=1; i<=n; i++) v[i]+=v[i-1];
    
    sort(v.begin()+1, v.end());
    
    cout << v[(n/2)+1];
    return 0;
}
