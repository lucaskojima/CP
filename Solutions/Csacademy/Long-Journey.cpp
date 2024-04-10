#include "bits/stdc++.h"
using namespace std;

const int MAXN=1e5+10;
vector<int>adj[MAXN];
int ans=0, vis[MAXN], dista[MAXN], distb[MAXN];

void bfs(int x, char seed){
    queue<int>q; q.push(x);
    vis[x]=1;
    while(!q.empty()){
        int c=q.front(); q.pop();
        for(auto k : adj[c]){
            if(vis[k]==1) continue;
            q.push(k);
            vis[k]=1;
            if(seed=='a') dista[k]=dista[c]+1;
            if(seed=='b') distb[k]=distb[c]+1;
        }
    }
}

void dfs(int x, int val){
    vis[x]=1;
    for(auto k : adj[x]){
        if(vis[k]==0 && dista[x]==dista[k]+1 && distb[x]==distb[k]+1){
                ans=max(ans, val+1);
                dfs(k, val+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    int s, a, b; cin >> s >> a >> b;

    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(a, 'a'); for(int i=1; i<=n; i++) vis[i]=0;
    bfs(b, 'b'); for(int i=1; i<=n; i++) vis[i]=0;

    dfs(s, 0);

    cout << ans << '\n';
    return 0;
}
