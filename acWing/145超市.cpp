#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<pair<int,int>> v(N);
priority_queue<int, vector<int>, greater<int>> q;
int main() {
    int n;
    while(cin >> n) {
        for(int i = 0; i < n; i++)
            cin >> v[i].second >> v[i].first;
        sort(v.begin(), v.begin()+n);
        for(int i = 0; i < n; i++) {
            q.push(v[i].second);
            if(v[i].first < (int)q.size())
                q.pop();
        } 
        int ans = 0;
        while(q.size())
            ans += q.top(),
            q.pop();
        cout << ans << endl;
    }
}