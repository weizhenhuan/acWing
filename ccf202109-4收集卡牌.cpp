#include <iostream>
using namespace std;
int n, k;
double p[200005];
double dp[400005][205];//dp[i][j]为i状态下手中有j个硬币的概率
double ans = 0;
int get(int x) {
    int ret = 0;
    while(x) {
        ret += (x & 1);
        x >>= 1;
    }
    return ret;
}
int main() {
    cin >> n >> k;
    
    for(int i = 0; i <= 200005; i++) {
        for(int j = 0; j <= 10; j++) {
            dp[i][j] = 0;
        }
    }
    for(int i = 0; i <= 100; i++) {
        dp[0][i] = 1;
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for(int i = 1; i < (1 << n); i++) {
        for(int j = 0; j <= k * n; j++) {
            //直接抽卡获得
            for(int k = 0; k < n; k++) {
                if(((i >> k) & 1) && !(get(i ^ (1 << k)) == 0 && j)) {//不可能从dp[0][x]转移过来
                    int pre = i ^ (1 << k);
                    if(dp[pre][j] >= 0) dp[i][j] += dp[pre][j] * p[k + 1];
                }
            }
            //没抽到
            for(int k = 0; k < n; k++) {
                if(j != 0 && ((i >> k) & 1)) {
                    if(dp[i][j - 1] >= 0) {
                        dp[i][j] += dp[i][j - 1] * p[k + 1];
                        
                    }
                }
            }
            int num = get(i);
            if(num == n || num + (j / k) >= n) {//满足条件才能更新答案
                ans = ans + dp[i][j] * (num + j);
                dp[i][j] = -1;//到此为止 不会继续抽了
            }
        }
    }
    printf("%.10lf", ans);//%.10lf没问题 %.8lf会0分
    return 0;
}