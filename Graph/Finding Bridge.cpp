const int MAX = 1e3 + 1;
vector<int> adj[MAX];
vector<pair<int, int>> ans;
bool mark[MAX];
int start[MAX], low[MAX], timing;
void dfs(int at, int parent = -1){
    start[at] = low[at] = timing++;
    mark[at] = 0;
    for(auto m : adj[at]){
        if(m == parent) continue;
        if(!mark[m]) low[at] = min(low[m], low[at]);
        else{
            dfs(m, at);
            low[at] = min(low[m], low[at]);
            if(low[m] > start[at]){
                int x = at;
                int y = m;
                if(x > y) swap(x, y);
                ans.emplace_back(x, y);
            }
        }
    }
}
