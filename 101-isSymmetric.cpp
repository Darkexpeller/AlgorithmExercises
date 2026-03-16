#include <stdio.h>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        

    }
    TreeNode *invertTree(TreeNode* root){
        if(root!=nullptr){
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        if(root->left!=nullptr)
            invertTree(root->left);
        if(root->right!=nullptr)
            invertTree(root->right);
        return root;
    }
};