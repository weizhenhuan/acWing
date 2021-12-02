#include <bits/stdc++.h>
using namespace std;

int mapp[605][605] = {0};
int dp[605][605] ={0};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,l,r,t;
    int ret = 0;
    cin >> n >> l >> r >> t;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> mapp[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mapp[i][j];
        }
    }    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int r1 = max(1, i - r);
            int r2 = min(n, i + r);
            int c1 = max(1, j - r);
            int c2 = min(n, j + r);
            int sum = dp[r2][c2] - dp[r2][c1-1] - dp[r1-1][c2] + dp[r1-1][c1-1];
            int cnt = (r2 - r1 + 1) * (c2 - c1 + 1);
            if(sum <= cnt * t) 
                ret ++;
        }
    }
    cout << ret;
}