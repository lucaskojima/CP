#include "bits/stdc++.h"
using namespace std;

void setIO(string s) {
    ios::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

#define int long long
#define ff first
#define ss second
using pii=pair<int, int>;

int n; vector<pii>v;

int calc(){
    vector<pii>pref(n+1), suf(n+1);

    sort(v.begin(), v.end());

    pref[1]={v[1].ss, v[1].ss};
    for(int i=2; i<=n; i++){
        pref[i]={min(pref[i-1].ff, v[i].ss), max(pref[i-1].ss, v[i].ss)};
    }
    suf[n]={v[n].ss, v[n].ss};
    for(int i=n-1; i>=1; i--){
        suf[i]={min(suf[i+1].ff, v[i].ss), max(suf[i+1].ss, v[i].ss)};
    }

    int ini=(v[n].ff-v[1].ff)*(pref[n].ss-pref[n].ff);
    int fim=(v[n].ff-v[1].ff)*(pref[n].ss-pref[n].ff);

    for(int i=1; i<=n-1; i++){
        if(v[i].ff!=v[i+1].ff){
            int a1=(v[i].ff-v[1].ff)*(pref[i].ss-pref[i].ff);
            int a2=(v[n].ff-v[i+1].ff)*(suf[i+1].ss-suf[i+1].ff);
            fim=min(fim, a1+a2);
        }
    }

    return ini-fim;
}

int32_t main(){
    setIO("split");

    cin >> n; v.resize(n+1);

    for(int i=1; i<=n; i++) cin >> v[i].ff >> v[i].ss;

    int ans=0;
    ans=max(ans, calc());
    for(int i=1; i<=n; i++) swap(v[i].ff, v[i].ss);
    ans=max(ans, calc());

    cout << ans;
    return 0;
}
