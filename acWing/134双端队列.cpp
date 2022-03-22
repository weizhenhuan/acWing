// 队列，单谷性质
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 200010;
PII a[N];

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);

  int dir = -1; // -1: down, 1: up
  int res = 1;
  int last = n;
  for(int i = 0; i < n; ) {
    int j = i;
    while(j < n && a[j].first == a[i].first) 
      j++;
    int minx = a[i].second;
    int maxx = a[j-1].second;
    if (dir == -1) {
      if (maxx < last)
        last = minx;
      else {
        dir = 1;
        last = maxx;
      }
    }
    else {
      if (minx > last)
        last = maxx;
      else {
        last = minx;
        dir = -1;
        res++;
      }      
    }
    i = j; 
  }
  cout << res << endl;
}