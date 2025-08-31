/**
 * Description: single source shortest path with negative edges
 * Source:
    * https://cp-algorithms.com/graph/bellman_ford.html
    * https://github.com/bqi343/cp-notebook/blob/master/Implementations/content/graphs%20(12)/Basics/BellmanFord%20(7.3).h
 * Verification: https://open.kattis.com/submissions/17769695
 * Time: O(VE)
 */

void bellmanFord(int n, int s, vector<vector<int>> adj, vector<tuple<int, int, int>> edges) {
  vector<int> d(n + 1, INF);
  d[s] = 0;

  for (int i = 0; i < n - 1; i++)
    for (auto [a, b, w] : edges)
      if (d[a] < INF)
        d[b] = min(d[b], d[a] + w);

  auto rec = [&](auto rec, int x) -> void {
    if (d[x] == -INF) return;
    d[x] = -INF;
    for (int k : adj[x])
      rec(rec, k);
  };

  for (auto [a, b, w] : edges)
    if (d[a] < INF)
      if (d[a] + w < d[b])
        rec(rec, b);
}
