#include <stdio.h>
#include <vector>
#include <algorithm>
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
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int lret = 1;
        int rret = 1;
        if(root->left!=nullptr){
            lret += maxDepth(root->left);
        }
        if(root->right!=nullptr){
            rret += maxDepth(root->right);
        }
        if(root->left == nullptr && root->right == nullptr)
            return 1;
        return max(lret,rret);
    }
};