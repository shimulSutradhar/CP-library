#include <bits/stdc++.h>
using namespace std;

// Compute a potential p for the graph G.
// Create a new weighting w′ of the graph, where w′(u→v)=w(u→v)+p(u)−p(v).
// Compute all-pairs shortest paths dist′ with the new weighting.
// Convert the distances back to the original graph, with the equation dist(u→v)=dist′(u→v)−p(u)+p(v).

using init = long long;
struct Edge{
  int u = 0;
  int v = 0;
  int w = 0;
  Edge(){}
  Edge(int u = 0, int v = 0, int w = 0):
  u(u), v(v), w(w){}
};
const int MAX = 2007;
const init inf = 1e15 + 7;
vector<pair<int, init>> adj[MAX];
vector<Edge> edges;
init dist[MAX] [MAX], h[MAX], dijk_dist[MAX], potential[MAX];

bool bellman_ford(int n, int m) {
  for (int i = 1; i <= n; i++) {
    h[i] = inf;
    edges.emplace_back(0, i, 0);
  }
  
  h[0] = 0;
  bool is_cycle = true;
  for (int i = 1; i <= n; i++) {
    is_cycle = false;
    for (int j = 0; j < m; j++) {
      if (h[edges[j].v] > h[edges[j].u] + edges[j].w) {
        h[edges[j].v] = h[edges[j].u] + edges[j].w;
        is_cycle = true;
      }
    }
    if (!is_cycle) break;
  }
  
  for (int i = 1; i <= n; i++) {
    edges.pop_back();
  }
  return is_cycle;
}

void dijkstra(int s, int n) {
  for (int i = 0; i <= n; i++) {
    dijk_dist[i] = potential[i] = inf;
  }
  dijk_dist[s] = potential[s] = 0;
  set<pair<init, int>> q;
  q.emplace(0, s);

  while (!q.empty( )) {
    init w = (*q.begin( )).first;
    int u = (*q.begin( )).second;
    q.erase(*q.begin( ));

    if (potential[u] != w) {
      continue;
    }

    for (auto [v, _w] : adj[u]) {
      if (potential[v] > potential[u] + _w + h[u] - h[v]) {
        q.erase({potential[v], v});
        dijk_dist[v] = dijk_dist[u] + _w;
        potential[v] = potential[u] + _w + h[u] - h[v];
        q.emplace(potential[v], v);
      }
    }
  }
}
void Johnsons_Algorithm(int n, int m) {
  if (bellman_ford(n, n + m)) {
    puts("Negative cycle");
    return;
  }
  
  for (int i = 0; i < m; i++) {
    adj[edges[i].u].emplace_back(edges[i].v, edges[i].w);
  }

  for (int i = 1; i <= n; i++) {
    dijkstra(i, n);
    for (int j = 1; j <= n; j++) {
      dist[i] [j] = dijk_dist[j];
    }
  }
  
  for (int i = 0; i <= n; i++) {
    adj[i].clear( );
  }
}
int main( ) {
  int tc, n, m, u, v, w;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &u, &v, &w);
    edges.emplace_back(u, v, w);
  }
  Johnsons_Algorithm(n, m);
  return 0;
}
