// O(n*m)
const int inf = 1e8 + 7;
struct edge{
  int v = 0;
  int u = 0;
  int w = 0;
  edge(int v = 0, int u = 0, int w = 0):v(v), u(u), w(w){}
};
vector<edge> edges;
bool bellmanford(int s, int n) {
  vector<int> dist(n + 7, inf);
  
  dist[s] = 0;
  for (int i = 1; i < n; i++) {
    for (edge e : edges) {
      if (dist[e.v] > dist[e.u] + e.w) {
        dist[e.v] = dist[e.u] + e.w;
      }
    }
  }
  
  bool is_cycle = false;
  for (edge e : edges) {
    if (dist[e.v] > dist[e.u] + e.w) {
      is_cycle = true;
      break;
    }
  }
  
  return is_cycle;
}
