#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MAX = 1e4;

vector<pair<int, int>> adj[MAX];
int Heavy[MAX], Head[MAX],Parent[MAX], Pos[MAX], arr[MAX], curent_pos;
int ett[MAX], depth_node[MAX], last_appearance[MAX], timer;
// lca
void euler_toue(int at = 1, int depth = 0, int parent = -1){
    depth_node[timer] = depth;
    last_appearance[at] = timer;
    ett[timer++] = at;
    for(auto m : adj[at]){
        if(m.f == parent){
            continue;
        }
        euler_toue(m.f, depth + 1, at);
        last_appearance[at] = timer;
        depth_node[timer] = depth;
        ett[timer++] = at;
    }
}

//sparse table
int st[MAX] [20], logs[MAX];
template <typename t>
t f(t a, t b){
    if(depth_node[a] > depth_node[b]){
        return b;
    }
    return a;
}
void preprocess( ){
    for(int i = 2; i < MAX; i++){
        logs[i] = logs[i / 2] + 1;
    }
}
void sp_build(int n){
    for(int i = 0; i <= n; i++){
        st[i] [0] = i;
    }
    for(int i = 1; i <= logs[n]; i++){
        for(int j = 0; j + (1 << i) <= n; j++){
            st[j] [i] = f(st[j] [i - 1], st[j + (1 << (i - 1))] [i - 1]);
        }
    } 
}

int lca_queary(int l, int r){
    l = last_appearance[l];
    r = last_appearance[r];
    if(l > r){
        swap(l, r);
    }
    int k = logs[r - l + 1];
    return ett[f(st[l] [k], st[r - (1 << k) + 1] [k])];
}

//segment tree
int Tree[4 * MAX];
void build(int at, int left, int right){
    if(left == right){
        Tree[at] = arr[left];
        return;
    }
    int mid = (left + right) >> 1;
    build(2 * at, left, mid);
    build(2 * at + 1, mid + 1, right);
    Tree[at] = Tree[2 * at] + Tree[2 * at + 1];
}
int queary(int at, int L, int R, int l, int r){
    if(r < L || R < l) return 0;
    if(l <= L && R <= r){
        return Tree[at];
    }
    int mid = (L + R) >> 1;
    int x = queary(2 * at, L, mid, l, r);
    int y = queary(2 * at + 1, mid + 1, R, l, r);
    return x + y;
}

// HLD
int Hld_dfs(int at = 1, int parent = -1){
    int _size = 1, max_size = 0;
    for(auto m : adj[at]){
        if(m.f == parent) continue;
        Parent[m.f] = at;
        int mk = Hld_dfs(m.f, at);
        if(mk > max_size){
            max_size = mk;
            Heavy[at] = m.f;
        }
        _size += mk;
    }
    return _size;
}

void Decompose(int at = 1, int h = 1, int weight = 0, int parent = 1){
    // cout << at << ' ' << weight << '\n';
    arr[curent_pos] = weight;
    Head[at] = h, Pos[at] = curent_pos++;
    if(Heavy[at]){
        for(auto m : adj[at]){
            if(m.f == Heavy[at]){
                Decompose(Heavy[at], h, m.s, at);
                break;
            }
        }
    }
    for(auto m : adj[at]){
        if(m.f == parent || m.f == Heavy[at]) continue;
        Decompose(m.f, m.f, m.s, at); 
    }
}

void HLD_build(){
    curent_pos = 0, timer = 0;
    Hld_dfs();
    Decompose();
    build(1, 0, curent_pos);
    euler_toue();
    sp_build(timer);
    depth_node[timer] = INT_MAX;
}

int HLD_queary(int l, int r, int lca_node){
    int ans = 0;
    for(int i = 0; i < 2; i++){
        if(i == 1) l = r;
        while(Head[l] != Head[lca_node]){
            int x = Pos[l], y = Pos[Head[l]];
            if(x > y) swap(x, y);
            ans += queary(1, 0, curent_pos, x, y);
            l = Parent[Head[l]];
        }
        if(l != lca_node){
            int x = Pos[l], y = Pos[Heavy[lca_node]];
            if(x > y) swap(x, y);
            ans += queary(1, 0, curent_pos, x, y);
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    preprocess( );
    int n;
    cin >> n;
    while(n--){
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].emplace_back(y, w);
        adj[y].emplace_back(x, w);
    }
    HLD_build();
    cout << HLD_queary(8, 5, lca_queary(8, 5));
    return 0;
}
