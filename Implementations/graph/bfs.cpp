/**
 * Description: shortest paths in unweighted graphs
 * Source: https://usaco.guide/gold/unweighted-shortest-paths
 * Verification: https://cses.fi/problemset/result/15121618/
 * Time: O(V + E)
 */

void bfs(int s) {
  vector<int> d(n + 1, INF);
  queue<int> q;
  q.push(s); d[s] = 0;

  while (!q.empty()) {
    int x = q.front(); q.pop();
    for (int k : adj[x]) {
      if (d[k] != INF) continue;

      q.push(k);
      d[k] = d[x] + 1;
    }
  }
}
