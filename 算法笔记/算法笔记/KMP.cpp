#include <bits/stdc++.h>
using namespace std;

int next[100];

bool kmp(string x, string y);
void getNext(string y, int n);

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string x = "abababaabc";
  string y = "baabc";

  bool ans = kmp(x, y);
  cout << ans;
  return 0;
}


bool kmp(string x, string y) {
  int m = x.size();
  int n = y.size();
  getNext(y, n);

  int j = -1;
  for (int i = 0; i < m; i++) {
    while (j != -1 && x[i] != y[j+1])
      j = ::next[j];
    
    if (x[i] == y[j+1])
      j += 1;
    if (j == n-1)
      return true;
  }
  return false;
}


void getNext(string y, int n) {
  int j = -1;
  ::next[0] = -1;
  for (int i = 1; i < n; i++) {
    while (j !=- 1&& y[i] != y[j+1])
      j = ::next[j];
  
    if (y[i] == y[j+1])
      j += 1;
    ::next[i] = j;
  }
}