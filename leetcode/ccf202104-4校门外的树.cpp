#include <bits/stdc++.h>
using namespace std;

const int AI = 100005;
const int MOD = 1e9+7;
const int N = 1005;

bool used[AI];
vector<int> yinzi[AI];
int a[N];
long long ret[N] = {0};

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 1; i < AI; i++) {
        for(int j = i+i; j < AI; j += i) 
            yinzi[j].push_back(i); 
    }
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ret[1] = 1;
    for(int i = 2; i <= n; i++) {
        memset(used, false, sizeof(used));
        for(int j = i - 1; j >= 1; j--) {
            int cnt = 0;
            int d = a[i] - a[j];
            for(int k : yinzi[d]) {
                if(!used[k]) {
                    used[k] = true;
                    cnt++;
                }
            }
            used[d] = true;
            ret[i] = (ret[i] + cnt * ret[j]) % MOD;
        }
    }
    cout << ret[n];
}