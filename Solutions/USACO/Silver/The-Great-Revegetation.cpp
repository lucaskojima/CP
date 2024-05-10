#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

template<typename T>
using matrix = vector<vector<T>>;
using pii = pair<int, int>;
using ll = long long;

const ll LINF = (1LL<<60);
const int INF = (1<<30);
const int MAXN = 1e5+10;

vector<pair<int, char>>adj[MAXN];
int vis[MAXN], col[MAXN];
bool ok=true;

void dfs(int x, int c){
    vis[x]=1;
    for(auto k : adj[x]){
        if(k.ss=='S'){
            if(col[k.ff]==3-c) ok=false;
            col[k.ff]=c;
            if(vis[k.ff]==0) dfs(k.ff, c);
        }
        if(k.ss=='D'){
            if(col[k.ff]==c) ok=false;
            col[k.ff]=3-c;
            if(vis[k.ff]==0) dfs(k.ff, 3-c);
        }
    }
}

void setIO(string s){
    ios::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("revegetate");

    int n, m; cin >> n >> m;

    for(int i=0; i<m; i++){
        char c; int a, b; cin >> c >> a >> b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int comp=0;
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            col[i]=1;
            dfs(i, 1); comp++;
        }
    }

    if(!ok){cout << "0"; return 0;}

    cout << "1";
    for(int i=0; i<comp; i++){
        cout << "0";
    }
    return 0;
}
