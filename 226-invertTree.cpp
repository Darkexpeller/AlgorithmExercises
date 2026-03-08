/**g++ 226-invertTree.cpp -o 226-invertTree
 * Definition for a binary tree node. 翻转二叉树
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    TreeNode* invertTree(TreeNode* root) {
    if(root!=nullptr){
        TreeNode *temp=nullptr;
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }else{
        return nullptr;
    }
    
    if(root->left!=nullptr){
        invertTree(root->left);
    }
    if(root->right!=nullptr){
        invertTree(root->right);
    }
    return root;
}
};