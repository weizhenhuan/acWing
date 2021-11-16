#include <bits/stdc++.h>
using namespace std;

int ret[260] = {0};

int main() {
    int m,n,l;
    cin >> n >> m >> l;
    for (int i = 0; i < n * m; ++i) {
        int gray;
        cin >> gray;
        ret[gray] ++;
    }    
    for(int i = 0; i < l; i++)
        cout << ret[i] << " ";
}