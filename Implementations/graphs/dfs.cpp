// Time Complexity: O(V+E)

void dfs(int x){
	vis[x]=1;
	for(int i=0; i<adj[x].size(); i++){
		int k=adj[x][i];
		if(vis[k]==0){
			dfs(k);
		}
	}
}
