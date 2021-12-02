#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int B[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, min_ans = 0, max_ans = 0;
    int pre = -1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> B[i];
        max_ans += B[i];
        if(B[i] != pre) {
            min_ans += B[i];
            pre = B[i];
        }
    }
    cout << max_ans << endl;
    cout << min_ans;
    return 0;
}