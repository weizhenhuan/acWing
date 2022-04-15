#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
            cout << "pre: " << pre << "  maxAnx: " << maxAns << endl;
        }
        return maxAns;
    }

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  vector<int> nums = {5, 4, -1, 7, 8};  
  cout << maxSubArray(nums) << endl;
  return 0;
}