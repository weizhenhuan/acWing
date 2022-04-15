// 用邻接表实现prim 最小生成树算法
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int v, w;
};

const int maxn = 1000;
int n;
int d[maxn];
bool vis[maxn];
vector<Node> Adj[maxn];

int ans = 0;

int prim() {
  fill(d, d+maxn, INT_MAX);
  memset(vis, 0, sizeof(vis));

  vis[0] = true;
  d[0] = 0;

  for (size_t i = 0; i < n; i++) {
    int u = -1, MIN = INT_MAX; 
    for (size_t j = 0; j < n; j++) {
      if (!vis[j] && d[j] < MIN) {
        MIN = d[j];
        u = j;
      } 
    }
    if (u == -1)
      return -1;

    vis[u] = true;
    ans += d[u];

    for (size_t j = 0; j < Adj[u].size(); j++) {
      int v = Adj[u][j].v;
      if (!vis[v] && d[v] > Adj[u][j].w)
        d[v] = Adj[u][j].w;
    }
  }

  return ans;
}

