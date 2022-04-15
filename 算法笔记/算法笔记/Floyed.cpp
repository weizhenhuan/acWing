#include <bits/stdc++.h>
using namespace std;

int n, m;
const int maxn = 10000;

int d[maxn][maxn];

void init() {
  fill(d, d + maxn * maxn, INT_MAX);
  for (size_t i = 0; i < n; i++) {
    d[i][i] = 0;
  }
}

void Floyed() {
  init();
  for (size_t k = 0; k < n; k++) {
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n; j++) {
        if (d[i][k] != INT_MAX && d[k][j] != INT_MAX)
        d[i][j] = min(d[i][j], d[i][k]+ d[k][j]);
      } 
    }
  } 
}
