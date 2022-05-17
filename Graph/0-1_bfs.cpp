vector<long long> dist(n + 7, INT_MAX);
  deque<int> Q;
  Q.push_front(1);
  dist[1] = 0;
  while(!Q.empty()){
    int u = Q.front();
    Q.pop_front();
    for(auto m : adj[u]){
      if(dist[m.to] > m.weight + dist[u]){
        dist[m.to] = m.weight + dist[u];
        if(m.weight == 1){
          Q.push_back(m.to);
        }else{
          Q.push_front(m.to);
        }
      }
    }
  }
