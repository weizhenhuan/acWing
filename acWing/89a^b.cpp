#include <bits/stdc++.h>
using namespace std;

int calc(int a, int b, int p) {
    int ans = 1;
    while(b) {
        if(b & 1)
            ans = (long long)ans * a % p;
        b >>= 1;
        a = (long long)a * a % p;
    }
    return ans % p;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,p;
    cin >> a >> b >> p;
    int ans = calc(a,b,p);
    cout << ans << endl;
}