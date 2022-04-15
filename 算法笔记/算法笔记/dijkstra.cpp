#include <bits/stdc++.h>
using namespace std;

const int N = 16;
int e[N][N];
int vis[N];
pair<int, string> dis[N];

void init();
void link(int u, int v, int w);
void dijkstra(int s);

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j)
        e[i][j] = 0;
      else e[i][j] = INT_MAX;
    }
  } 

  init();
  dijkstra(0);

  cout << "the minimus distance is " << dis[N-1].first << endl;
  cout << dis[N-1].second << endl;
  return 0;
}

void init() {
  link(0,1,5);
  link(0,2,3);
  link(1,3,1);
  link(1,4,3);
  link(1,5,6);
  link(2,4,8);
  link(2,5,7);
  link(2,6,6);
  link(3,7,6);
  link(3,8,8);
  link(4,7,3);
  link(4,8,5);
  link(5,8,3);
  link(5,9,3);
  link(6,8,8);
  link(6,9,4);
  link(7,10,2);
  link(7,11,2);
  link(8,11,1);
  link(8,12,2);
  link(9,11,3);
  link(9,12,3);
  link(10,13,3);
  link(10,14,5);
  link(11,13,5);
  link(11,14,2);
  link(12,13,6);
  link(12,14,6);
  link(13,15,4);
  link(14,15,3);
}

void link(int u, int v,int w) {
  e[u][v] = w;
  e[v][u] = w;
}

void dijkstra(int s) {
  for (int i = 0; i < N; i++) {
    dis[i].first = e[s][i];
    dis[i].second = to_string(s) + " -> " + to_string(i);
  }
  
  vis[s] = 1;
  for (int i = 0; i < N-1; i++) {
    int min_dis = INT_MAX;
    int min_idx = -1;
    for (int j = 0; j < N; j++) {
      if (!vis[j] && dis[j].first < min_dis) {
        min_dis = dis[j].first;
        min_idx = j;
      }
    }

    vis[min_idx] = 1;

    for(int j = 0; j < N; j++) {
      if (e[min_idx][j] < INT_MAX && !vis[j] && dis[j].first > dis[min_idx].first + e[min_idx][j]) {
        dis[j].first = dis[min_idx].first + e[min_idx][j];
        dis[j].second = dis[min_idx].second + " -> " + to_string(j);
      }
    }
  }
}