// 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，
// 请构造二叉树并返回其根节点。
#include<iostream>
#include<vector>
#include <unordered_map>
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
    unordered_map<int, int> index_map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //先对中序数组构造map
        int n = preorder.size();
        for (int i = 0; i < n;i++){
            index_map[inorder[i]] = i;
        }
        return myBuildTree(preorder, 0, n - 1, 0, n - 1);
    }
    TreeNode* myBuildTree(const vector<int>& preorder, int pre_left, int pre_right, int in_left, int in_right){
        if (pre_left > pre_right) return nullptr;
        TreeNode *root = new TreeNode;
        int root_val = preorder[pre_left];
        root->val = root_val;
        int inorder_index = index_map[root_val];
        //计算左子树的大小
        int left_tree_size = inorder_index - in_left;

        root->left = myBuildTree(preorder, pre_left + 1, pre_left+left_tree_size, in_left, inorder_index - 1);
        root->right = myBuildTree(preorder,pre_left+left_tree_size+1, pre_right, inorder_index + 1, in_right);
        return root;
    }
};