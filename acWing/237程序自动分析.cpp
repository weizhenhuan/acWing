// 并查集
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 2*1e5 + 5;
int fa[2 * N];
unordered_map<int, int> H;
vector<PII> aa;
int cnt = 0;

int mapping(int i) {
  if (H.count(i)) return H[i];
  H[i] = cnt++;
  return H[i];
}

void init() {
  for(int i = 0; i < N; i++) {
    fa[i] = i;
  }
}

int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
  fa[find(x)] = find(y);
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t; 
  
  while (t--) {
    init();
    cnt = 0;
    int i, j, e, n;
    cin >> n;
    while (n--) {
      cin >> i >> j >> e;
      i = mapping(i);
      j = mapping(j);
      if (e == 1) 
        merge(i, j);
      else 
        aa.push_back(make_pair(i, j));
    }
    int flag = 1;
    for (auto b : aa) {
      if (find(b.first) == find(b.second)) {
        flag = 0;
        break; 
      }
    }
    if (flag) 
      cout << "YES" << endl;
    else cout << "NO" << endl;
    aa.clear();
    H.clear();
  }

  return 0;
}