#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int v, w;
};


const int maxn = 1000;
int n;
int dis[maxn];
int num[maxn];
bool vis[maxn];
vector<Node> Adj[maxn];

bool SPFA(int s) {
  memset(vis, 0 , sizeof(vis));
  memset(num, 0, sizeof(num));
  fill(dis, dis+maxn, INT_MAX);

  queue<int> q;
  q.push(s);
  num[s] ++;
  vis[s] = true;
  dis[s] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = false;

    for (size_t i = 0; i < Adj[u].size(); i++) {
      int v = Adj[u][i].v;
      if (dis[v] > dis[u] + Adj[u][v].w) {
        dis[v] = dis[u] + Adj[u][v].w;
        if (!vis[v]) {
          q.push(v);
          num[v] ++;
          vis[v] = true;
        
          if (num[v] >= n)
            return false;
        }
      }
    }
  }  
  return true;
}


