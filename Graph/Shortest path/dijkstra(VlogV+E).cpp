using i64 = long long;
const int MAX = 1e5 + 7;
vector<pair<int, int>> adj[MAX];

i64 Dijkstra(int s, int n) {
  vector<i64> dist(n + 7, (i64)1e14);
  dist[s] = 0;
  set<pair<i64, int>> q;
  q.emplace(0, s);
  while (!q.empty( )) {
    auto u = *q.begin( );
    q.erase(*q.begin( ));

    if (dist[u.second] != u.first) {
      continue;
    }

    for (auto v : adj[u.second]) {
      if (dist[v.first] > dist[u.second] + v.second) {
        q.erase({dist[v.first], v.first});
        dist[v.first] = dist[u.second] + v.second;
        q.emplace(dist[v.first], v.first);
      }
    }
  }
  return dist[n];
}
