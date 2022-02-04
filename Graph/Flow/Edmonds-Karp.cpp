const int MAX = 507;
long long capacity[MAX] [MAX];
vector<int> adj[MAX];
int parent[MAX];
int s, t;
long long bfs(){
    memset(parent, -1, sizeof parent);
    parent[s] = -2;
    queue<pair<int, long long>> q;
    q.push({1, LONG_MAX});
    while (!q.empty( )){
        int node = q.front().first;
        long long flow = q.front().second;
        q.pop();
        for(auto m : adj[node]){
            if(capacity[node] [m] > 0 && parent[m] == -1){
                parent[m] = node;
                long long new_flow = min(flow, capacity[node] [m]);
                if(m == t){
                    return new_flow;
                }
                q.push({m, new_flow});
            }
        }
    }
    return 0ll;
}
long long max_flow(){
    long long total_flow = 0, new_flow;
    while(new_flow = bfs()){
        total_flow += new_flow;
        int curent = t;
        while(curent != s){
            int now = parent[curent];
            capacity[now] [curent] -= new_flow;
            capacity[curent] [now] += new_flow;
            curent = now;
        }
    }
    return total_flow;
}
