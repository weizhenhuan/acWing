#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 10e5+5;
int h[N];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while(cin >> n && n) {
        memset(h, 0, sizeof(h));
        stack<int> width;
        stack<int> s;
        s.push(0);
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            cin >> h[i];
        }
        for(int i = 1; i <= n + 1; i++) {
            if(h[i] > s.top()) {
                s.push(h[i]);
                width.push(1);
            }
            else {
                int j = i - 1;
                int w = 1;
                while(!s.empty() && s.top() >= h[i]) {
                    int height = s.top();
                    s.pop();
                    w += width.top();
                    width.pop();
                    ans = max(ans, (ll)height * w);
                    j--;
                }
                s.push(h[i]);
                width.push(w);
            }
        } 
        cout << ans << endl;
    }
}