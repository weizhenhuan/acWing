#include <bits/stdc++.h>
using namespace std;

const int N = 12;
int d[N+1];
int f[N+1];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    d[1] = 1;
    for(int i = 2; i <= N; i++) {
        d[i] = 2 * d[i-1] + 1;
    }

    memset(f, 0x3f, sizeof(f));
    f[1] = 1;
    for(int i = 2; i <= N; i++) {
        for(int j = 1; j < i; j++) {
            f[i] = min(f[i], 2 * f[j] + d[i-j]);
        }
    }
    for(int i = 1; i <= N; i++)
        cout << f[i] << endl;
}