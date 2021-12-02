#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for(int num : nums)
            num_set.insert(num);
        int max_res = 0;
        for(int i = 0; i < nums.size();i++ ) {
            if(num_set.count(nums[i]-1) == 0) {
                int younum = 1;
                int youpos = nums[i];
                while (num_set.count(youpos + 1) != 0){
                    youpos++;
                    younum++;
                }
                max_res = max(max_res, younum);
            }
        }
        return max_res;
    }
};