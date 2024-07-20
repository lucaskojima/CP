#include <bits/stdc++.h>
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const char nl = '\n';
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;

void setIO(string s){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

int main(){
	setIO("mootube");

    int n, q; cin >> n >> q;

    vector<pair<int, pii>>adj;
    for(int i=0; i<n-1; i++){
        int a, b, w; cin >> a >> b >> w;
        adj.push_back({w, {a, b}});
    }

    vector<pair<int, pii>>query;
    for(int i=0; i<q; i++){
        int k, v; cin >> k >> v;
        query.push_back({k, {i, v}});
    }

    sort(rall(adj));
    sort(rall(query));

    vector<int>pai(n+1), prof(n+1), tam(n+1);

    auto init = [&]() -> void{
        for(int i=1; i<=n; i++) pai[i]=i, tam[i]=1;
    };
    auto find = [&](int v, auto &&find) -> int{
        if(pai[v]==v) return v;
        return pai[v]=find(pai[v], find);
    };
    auto une = [&](int a, int b) -> void{
        a=find(a, find); b=find(b, find);
        if(a==b) return;
        if(prof[a]<prof[b]) swap(a, b);

        pai[b]=a;
        tam[a]+=tam[b];
        if(prof[a]==prof[b]) prof[a]++;
    };

    init();

    vector<int>ans(q);
    int pos=0;

    for(int i=0; i<q; i++){
        auto [k, aux]=query[i];
        auto [idx, v]=aux;

        while(adj[pos].ff>=k){
            int a=adj[pos].ss.ff;
            int b=adj[pos].ss.ss;
            une(a, b);
            pos++;
        }

        ans[idx]=tam[find(v, find)]-1;
    }

    for(int i=0; i<q; i++) cout << ans[i] << nl;
	return 0;
}
