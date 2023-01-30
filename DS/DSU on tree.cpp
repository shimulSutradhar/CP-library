#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX(1e5 + 7);
vector<int> adj[MAX];
int Root[MAX], D[MAX];
set<int> S[MAX];

void dfs(int at, int parent) {
  int max_child = 0, ind = 0;
  for (int i : adj[at]) {
    if (i == parent) continue;
    dfs(i, at);
    if (D[i] > max_child) max_child = D[i], ind = i;
  }
  if (ind)
    Root[at] = Root[ind];
  for (int i : adj[at]) {
    if (i == parent || Root[i] == Root[at]) continue;
    for (auto it : S[Root[i]])
      // do work
    S[Root[i]].clear( );
  }
  D[at] = S[Root[at]].size( );
}

int main( ) {
  return 0;
}
