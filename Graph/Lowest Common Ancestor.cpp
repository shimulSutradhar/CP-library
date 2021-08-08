// tasted: (SPOJ) LCA - Lowest Common Ancestor
#include<bits/stdc++.h>
using namespace std;
const int MAX = 30007;
// euler tour
vector<int> adj[MAX];
int ett[MAX], depth_node[MAX], last_appearance[MAX], timer;
void euler_toue(int at, int depth = 0, int parent = -1){
  depth_node[timer] = depth;
  last_appearance[at] = timer;
  ett[timer++] = at;
  for(auto m : adj[at]){
    if(m == parent){
      continue;
    }
    euler_toue(m, depth + 1, at);
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
void build(int n){
  for(int i = 0; i <= n; i++){
    st[i] [0] = i;
  }
  for(int i = 1; i <= logs[n]; i++){
    for(int j = 0; j + (1 << i) <= n; j++){
      st[j] [i] = f(st[j] [i - 1], st[j + (1 << (i - 1))] [i - 1]);
    }
  } 
}

int queary(int l, int r){
  l = last_appearance[l];
  r = last_appearance[r];
  if(l > r){
    swap(l, r);
  }
  int k = logs[r - l + 1];
  return f(st[l] [k], st[r - (1 << k) + 1] [k]);
}

int main( ){
  preprocess( );
  return 0;
}
