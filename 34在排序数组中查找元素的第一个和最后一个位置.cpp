// 34 在排序数组中查找元素的第一个和最后一个位置
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;

        if(nums.empty()) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        
        int flag = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                if(flag) {
                    ret.push_back(i);
                    flag = 0;
                }   
            }
            else {
                if(!flag) {
                    ret.push_back(i-1);
                    break;
                }
            }
        }
        if(nums[nums.size()-1] == target)
            ret.push_back(nums.size() - 1);
        if(ret.empty()) {
            ret.push_back(-1);
            ret.push_back(-1);
        }
        return ret;
    }
};