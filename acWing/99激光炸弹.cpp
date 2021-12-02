#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 5001;
int price[N][N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    memset(price, 0, sizeof(price));
    int n,r;
    cin >> n >> r;
    for(int i = 1; i <= n; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        a += 1;
        b += 1;
        price[a][b] += c;
    }
    for(int a = 1; a <= 5001; a++) {
        for(int b = 1; b <= 5001; b++) {
            price[a][b] = price[a-1][b] + price[a][b-1] - price[a-1][b-1];
        }
    }
    for(int a = r; a <= 5001; a++) {
        for(int b = r; b <= 5001; b++) {
            ans = max(ans, price[a][b] - price[a-r][b] - price[a][b-r] + price[a-r][b-r]);
        }
    }
    cout << ans << endl;

}