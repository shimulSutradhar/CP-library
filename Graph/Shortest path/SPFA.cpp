// Average Time Complexity: O(E) 
// Worstcase Time Complexity: O(V*E) 

#include <bits/stdc++.h>
using namespace std;

using i64 = long long int;
const int MAX = 107;
const int inf = INT_MAX;
vector<pair<int, int>> adj[MAX];

bool SPFA(int s, int n) {
  vector<int> cnt(n + 7, 0);
  vector<i64> dist(n + 7, inf);
  vector<bool> in_queue(n + 7, false);
  queue<int> Q;
  
  Q.push(s);
  in_queue[s] = true;
  dist[s] = 0; 
  while (!Q.empty( )) {
    int from = Q.front( );
    in_queue[from] = false;
    Q.pop( );
    
    for (auto edge : adj[from]) {
      int to = edge.first;
      i64 cost = edge.second;
      
      if (dist[to] > dist[from] + cost) {
        dist[to] = dist[from] + cost;
        if (!in_queue[to]) {
          Q.push(to);
          in_queue[to] = true;
          ++cnt[to];
          if (cnt[to] > n) {
            // cycle found
            return true;
          }
        }
      }
    }
  }
  return false;
}
int main( ) {
  int n;
  srand (time(NULL));
  for (int i = 1; i <= n; i++) {
    random_shuffle(adj[i].begin( ), adj[i].end( ));
  }
  return 0;
}
