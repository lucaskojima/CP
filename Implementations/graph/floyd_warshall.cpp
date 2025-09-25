/**
 * Description: all-pairs shortest path with negative edges
 * Source:
    * https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html
    * https://github.com/bqi343/cp-notebook/blob/master/Implementations/content/graphs%20(12)/Basics/FloydWarshall%20(7.3).h
 * Verification: https://open.kattis.com/submissions/17769814
 * Time: O(V^3)
 */

void floydWarshall(int n, vector<vector<int>> d) {
  for (int i = 1; i <= n; i++)
    chmin(d[i][i], 0);

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (d[i][k] < INF && d[k][j] < INF) {
          int w = max(d[i][k] + d[k][j], -INF);
          chmin(d[i][j], w);
        }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if (d[i][k] < INF && d[k][k] < 0 && d[k][j] < INF)
          d[i][j] = -INF;
}
