// 采用边贪心的策略
#include <bits/stdc++.h>
using namespace std;

struct edge {
  int u, v;
  int w;
}E[maxn];

bool cmp(const edge &a, const edge &b) {
  return a.w < b.w;
}
const int maxn = 1000;
int fa[maxn];
int n, m;

int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}

int Kruscal() {
  int ans = 0;
  int num_edges = 0;
  for (size_t i = 0; i < n; i++) {
    fa[n] = n; 
  }

  sort(E, E+maxn, cmp);
  for (size_t i = 0; i < m; i++) {
     int u = E[i].u;
     int v = E[i].v; 
     if (find(u) != find(v)) {
        fa[u] = v;
        ans += E[i].w;
        num_edges ++;
        if (num_edges == n-1)
          break;
     }
  }

  if (num_edges == n-1)
    return ans;
  else return -1;
}

