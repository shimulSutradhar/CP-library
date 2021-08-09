#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 7;
struct node{
  int to = 0;
  int weight = 0;
  node(int to = 0, int weight = 0):to(to), weight(weight){}
};
vector<node> adj[MAX];
int node_cost[MAX], timer, first_time[MAX], anchestor_cost[MAX]; // path sum array
int ett[MAX], node_depth[MAX], last_time[MAX], ett_time; // lca
void dfs(int at = 0, int depth = 0, int parent = -1, int cost = 0){
  first_time[at] = timer;
  anchestor_cost[at] = cost;
  node_cost[timer++] = cost;

  ett[ett_time] = at;
  last_time[at] = ett_time;
  node_depth[ett_time++] = depth;
  for(node m : adj[at]){
    if(m.to == parent){
      continue;
    }
    dfs(m.to, depth + 1, at, m.weight);
    ett[ett_time] = at;
    last_time[at] = ett_time;
    node_depth[ett_time++] = depth;
  }
  node_cost[timer++] = -cost;
}
// lca queary
int st_lca[MAX] [18], logs[MAX];
inline int f_lcs(int a, int b){
  return node_depth[a] > node_depth[b] ? b : a;
}
void lca_build(int n){
  for(int i = 0; i < n; i++){
    st_lca[i] [0] = i;
  }
  for(int i = 1; i <= logs[n]; i++){
    for(int j = 0; j + (1 << i) <= n; j++){
      st_lca[j] [i] = f_lcs(st_lca[j] [i - 1], st_lca[j + (1 << (i - 1))] [i - 1]);
    }
  }
}
int lca_queary(int l, int r){
  l = last_time[l];
  r = last_time[r];
  if(l > r){
    swap(l, r);
  }
  int k = logs[r - l + 1];
  return ett[f_lcs(st_lca[l] [k], st_lca[r - (1 << k) + 1] [k])];
}
// segment tree
int tree[4 * MAX];
void build(int at, int left, int right){
  if(left == right){
    tree[at] = node_cost[left];
    return;
  }
  int mid = (left + right) >> 1;
  build(2 * at,        left,   mid);
  build(2 * at + 1, mid + 1, right);
  tree[at] = tree[2 * at] + tree[2 * at + 1];
}
int queary(int at, int left, int right, int l, int r){
  if(r < left || right < l){
    return 0;
  }
  if(l <= left && right <= r){
    return tree[at];
  }
  int mid = (left + right) >> 1;
  int x = queary(    2 * at,    left,   mid, l, r);
  int y = queary(2 * at + 1, mid + 1, right, l, r);
  return x + y;
}
// ans
int sum_queary(int l, int r){
  int ancestor = lca_queary(l, r);
  auto fix_queary = [&](int x, int y){
    x = first_time[x];
    y = first_time[y];
    if(x > y){
      swap(x, y);
    }
    return queary(1, 0, timer - 1, x, y);
  };
  int fist_sum = fix_queary(l, ancestor);
  int second_sum = fix_queary(r, ancestor);
  return fist_sum + second_sum - 2 * anchestor_cost[ancestor];
}
int main( ){
  for(int i = 2; i < MAX; i++){
    logs[i] = logs[i / 2] + 1;
  }
  timer = 0;
  dfs();
  lca_build(ett_time);
  build(1, 0, timer - 1);
  return 0;
}
