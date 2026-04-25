//给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历，
//postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //先对中序数组构造map
        int n = inorder.size();
        for (int i = 0; i < n;i++){
            index_map[inorder[i]] = i;
        }
        return myBuildTree(postorder, 0, n - 1, 0, n - 1);
    }
    TreeNode* myBuildTree(const vector<int>& postorder, int post_left, int post_right, int in_left, int in_right){
        if (post_left > post_right) return nullptr;
        TreeNode *root = new TreeNode;
        int root_val = postorder[post_right];
        root->val = root_val;
        int inorder_index = index_map[root_val];
        //计算左子树的大小
        int left_tree_size = inorder_index - in_left;

        root->left = myBuildTree(preorder, pre_left + 1, pre_left+left_tree_size, in_left, inorder_index - 1);
        root->right = myBuildTree(preorder,pre_left+left_tree_size+1, pre_right, inorder_index + 1, in_right);
        return root;
    }
};