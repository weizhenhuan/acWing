#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int maxSum = INT_MIN;
    int maxvalue(TreeNode* root) {
        if(!root)
            return 0;
        int leftvalue = max(maxvalue(root->left), 0);
        int rightvalue = max(maxvalue(root->right), 0);
        int youprice = root->val + leftvalue + rightvalue;
        maxSum = max(maxSum, youprice);
        return root->val + max(leftvalue, rightvalue);
    }

    int maxPathSum(TreeNode* root) {
        maxvalue(root);
        return maxSum;
    }
};