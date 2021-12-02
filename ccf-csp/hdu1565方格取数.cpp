// #include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int initialization(int n);
int get_value(int i, int j);

const int N = 22;
int state[17720];
int dp[N][17720];
int mapp[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while(cin >> n) {
        int ans = 0;
        int m = initialization(n);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++)
                cin >> mapp[i][j];
        }    
        memset(dp[0], 0, sizeof(dp[0]));
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < m; j++) {
                int max_value = 0;
                for(int k = 0; k < m; k++) {
                    if(!(state[j] & state[k]))
                        max_value = max(dp[i-1][k], max_value); 
                }
                dp[i][j] = max_value + get_value(i, j);
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
    }
}

int initialization(int n) {
    int cnt = 0;
    for(int i = 0; i < (1 << n); i++) {
        if(!(i & i << 1)) {
            state[cnt++] = i;
        }
    }
    return cnt;
}

int get_value(int i, int j) {
    int value = 0;
    int column = 1;
    int sta = state[j];
    while(sta) {
        if(sta & 1) 
            value += mapp[i][column];
        sta >>= 1;
        column ++;
    }
    return value;
}