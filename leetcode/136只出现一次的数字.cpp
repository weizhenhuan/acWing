#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for( int num : nums) {
            ans = ans xor num;
        }        
        return ans;
    }
};