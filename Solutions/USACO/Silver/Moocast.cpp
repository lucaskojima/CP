#include "bits/stdc++.h"
using namespace std;

struct point{int x, y, p;};

const int MAXN = 210;
vector<int>adj[MAXN];
int cont=0, vis[MAXN];

void dfs(int x){
    vis[x]=1; cont++;
    for(auto v : adj[x]){
        if(vis[v]==0){
            dfs(v);
        }
    }
}

void setIO(string s){
    ios::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("moocast");
    int n; cin >> n;

    vector<point>v;
    for(int i=0; i<n; i++){
        int x, y, p; cin >> x >> y >> p;
        v.push_back({x, y, p});
    }

    auto dist=[](point a, point b){
        int dx=(a.x-b.x)*(a.x-b.x);
        int dy=(a.y-b.y)*(a.y-b.y);
        return dx+dy;
    };

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int d=dist(v[i], v[j]);
            if((v[i].p*v[i].p)>d) adj[i].push_back(j);
            if((v[j].p*v[j].p)>d) adj[j].push_back(i);
        }
    }

    int ans=0;
    for(int i=0; i<n; i++){
        dfs(i);
        ans=max(ans, cont);
        memset(vis, 0, sizeof(vis)); cont=0;
    }

    cout << ans << '\n';
    return 0;
}
