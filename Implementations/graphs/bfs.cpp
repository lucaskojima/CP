// Time Complexity: O(V+E)

void bfs(int x){
    queue<int>q; q.push(x);
    vis[x]=1; //dist[x]=0;
    while(!q.empty()){
        int c=q.front();
        q.pop();
        for(int i=0; i<adj[c].size(); i++){
            int k=adj[c][i];
            if(vis[k]==1) continue;
            q.push(k);
            vis[k]=1;
            //dist[k]=dist[c]+1;
        }
    }
}
