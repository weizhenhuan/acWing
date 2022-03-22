// 单调栈
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 100005;
int a[N];
int s[N];
int w[N];
ll ans = -1;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  while(n != 0) {
    for(int i = 1; i <= n; i++)
      cin >> a[i];

    ans = 0;
    a[n+1] = 0;
    int p = 0;
    for (int i = 1; i <= n+1; i++) {
      if (a[i] > s[p]) {
        s[++p] = a[i];
        w[p] = 1;
      }
      else {
        int width = 0;
        while(a[i] < s[p]) {
          width += w[p];
          ans = max(ans, (ll)width*s[p]);
          p--; 
        }
        w[++p] = width + 1;
        s[p] = a[i];
      }
    }
    cout << ans << endl;
    cin >> n;
  }
}