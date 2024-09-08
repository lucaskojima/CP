// Time: O(V + E)

auto dfs = [&](auto dfs, int x) -> void {
	vis[x] = 1;
	for (auto k : adj[x]) {
		if (vis[k]) continue;
		dfs(dfs, k);
	}
};
