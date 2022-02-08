const int MAX = 1e3 + 7;
const int SIZE = 11;
vector<int> adj[MAX];
int dp[MAX] [SIZE];
int Start[MAX], End[MAX], Time;
void dfs(int at = 1, int parent = 1){
    Start[at] = Time++;
    dp[at] [0] = parent;
    for(int i = 1; i < SIZE; i++){
        dp[at] [i] = dp[dp[at] [i - 1]] [i - 1];
    }
    for(auto m : adj[at]){
        if(m == parent) continue;
        dfs(m, at);
    }
    End[at] = Time++;
}
bool is_lca(int u, int v){
    return Start[u] <= Start[v] && End[u] >= End[v];
}
int LCA(int u, int v){
    if(is_lca(u, v))
        return u;
    if(is_lca(v, u))
        return v;
    for(int i = SIZE - 1; i >= 0; i--){
        if(!is_lca(dp[u] [i], v)){
            u = dp[u] [i];
        }
    }
    return dp[u] [0];
}
