#include <bits/stdc++.h>
using namespace std;

const int P = 1e7 + 19;
const int MOD = 1e9 + 7;

long long hash_str(const string &s) {
    long long ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        ans = (ans * P + s[i]) % MOD;
    }
    return ans;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  

  return 0;
}