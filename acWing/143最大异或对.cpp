#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int tries[N*31][2];
int tot = 1;

void insert(int num) {
    int p = 1;
    for(int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if(tries[p][bit] == 0)
            tries[p][bit] = ++tot;
        p = tries[p][bit];
    }
}

int search(int num) {
    int p = 1;
    int result = 0;
    for(int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if(tries[p][!bit] == 0) {
            p = tries[p][bit];
        }
        else {
            result += 1 << i;
            p = tries[p][!bit];
        }
    }
    return result;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(tries, 0, sizeof tries);
    int n, ans = 0, a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        insert(a);
        ans = max(ans, search(a));
    }
    cout << ans << endl;
}