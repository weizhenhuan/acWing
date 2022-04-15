#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// H[i---j] = (H[j] - H[i-1] * P^(j-i+1) % MOD + MOD) % MOD;
const ll P = 1e7 + 19;
const ll MOD = 1e9 + 7;
const ll maxn = 1005;

ll pPow[maxn];
ll H1[maxn];
ll H2[maxn];
vector<pair<int, int>> pr1;
vector<pair<int, int>> pr2;

void init(int length) {
  pPow[0] = 1;
  for (int i = 1; i < length; ++i) {
    pPow[i] = pPow[i - 1] * P % MOD;
  }
}
void calc_H(const string &s, ll H[]) {
  H[0] = s[0];
  for (int i = 1; i < s.size(); i++) {
    H[i] = (H[i - 1] * P + s[i]) % MOD; 
  }
}

int hash_substr(ll H[], int l, int r) {
  if (l == 0)
    return H[r];
  else 
    return (H[r] - H[l-1] * pPow[r-l+1] % MOD + MOD) % MOD;
}

void calc_all_hash(ll H[], int len, vector<pair<int, int>> &pr) {
  for (int i = 0; i < len; i++) {
    for (int j = i; j < len; j++) {
      pr.push_back(make_pair(hash_substr(H, i, j), j - i + 1)); 
    }
  }
}

int get_max(vector<pair<int, int>> &pr1, vector<pair<int, int>> &pr2) {
  int ans = -1;
  for (auto &x: pr1) {
    for (auto &y: pr2) {
      if (x.first == y.first && x.second == y.second)
        ans = max(ans, x.second);
    }
  }
  return ans;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string x = "abcdefg";
  string y = "abcd";

  init(max(x.size(), y.size()));
  calc_H(x, H1);
  calc_H(y, H2);
  calc_all_hash(H1, x.size(), pr1);
  calc_all_hash(H2, y.size(), pr2);

  cout << get_max(pr1, pr2) << endl;
  return 0;
}