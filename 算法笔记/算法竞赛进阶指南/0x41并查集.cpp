#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int fa[N];
int dep[N];

void init() {
  for(int i = 0; i < N; i++) {
    fa[i] = i;
    dep[i] = 1;
  }
}

int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (dep[x] < dep[y]) swap(x, y);
  fa[y] = x;
  if (dep[x] == dep[y])
    dep[x]++;
}