#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < 2 * n -1; i++) {
            int left = i / 2;
            int right = left + i % 2;
            while(left >= 0 && right <= n-1 && s[left] == s[right]) {
                ans ++;
                left--;
                right ++;
            }
        }
        return ans;
    }
};