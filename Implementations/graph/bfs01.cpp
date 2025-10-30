/**
 * Description: shortest paths in 0/1 weighted graphs
 * Source: https://cp-algorithms.com/graph/01_bfs.html
 * Verification: *
 * Time: O(V + E)
 */

void bfs01(int s) {
  vector<int> d(n + 1, INF);
  deque<int> q;
  q.push_front(s); d[s] = 0;

  while (!q.empty()) {
    int x = q.front(); q.pop_front();

    for (auto [k, w] : adj[x]) {
      if (d[x] + w < d[k]) {
        d[k] = d[x] + w;
        if (w == 0)
          q.push_front(k);
        else
          q.push_back(k);
      }
    }
  }
}
