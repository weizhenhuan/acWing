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
    void flatten(TreeNode* root) {
        vector<TreeNode*> l;
        preorder(root,l);
        for(int i = 1; i < l.size(); i++) {
            l[i-1]->left = nullptr;
            l[i-1]->right = l[i];
        }
    }

    void preorder(TreeNode* root, vector<TreeNode*>& l) {
        if(!root)
            return;
        l.push_back(root);
        preorder(root->left, l);
        preorder(root->right, l);
    }
};