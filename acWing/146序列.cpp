#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int N = 2005;
int a[N], b[N], c[N];
int m, n;

void merge() {
    priority_queue<PII, vector<PII>, greater<PII>> q;
    for(int i = 0; i < n; i++)
        q.push(make_pair(a[0]+b[i], 0));
    for(int i = 0; i < n; i++) {
        c[i] = q.top().first;
        int index = q.top().second;
        q.pop();
        q.push(make_pair(c[i]-a[index]+a[index+1], index+1));
    }
    for(int i = 0; i < n; i++)
        a[i] = c[i];
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while(T --) {
        cin >> m >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];     
        }
        sort(a, a+n);
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n; j++) {
                cin >> b[j];
            }
            sort(b, b+n);
            merge();
        }
        
        for(int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}