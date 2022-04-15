#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
int n;
struct Node {
  int v, w;
};

vector<Node> Adj[maxn];
int d[maxn];

bool Bellman(int s) {
  fill(d, d+maxn, INT_MAX);
  for (size_t i = 0; i < n-1; i++) {
    for (size_t u = 0; u < n; u++) {
      for (size_t j = 0; j < Adj[u].size(); i++) {
        int v = Adj[u][j].v;
        d[v] = min(d[v], d[u] + Adj[u][j].w); 
      } 
    } 
  }

  // 判负代码
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < Adj[i].size(); j++) {
      int v = Adj[i][j].v;
      if (d[v] < d[i] + Adj[i][j].w)
        return false;
    } 
  }
  return true;
}
