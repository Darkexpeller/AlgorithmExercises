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
        if (root == nullptr) return true;
        // 树对不对称，取决于它的左右两棵子树是否互为镜像
        return checkMirror(root->left, root->right);
    }

private:
    bool checkMirror(TreeNode* leftNode, TreeNode* rightNode) {
        // 终止条件 1：两个节点同时为空，说明到底了，互为镜像，返回 true
        if (leftNode == nullptr && rightNode == nullptr) {
            return true;
        }
        // 终止条件 2：其中一个为空，另一个不为空，结构不对称，返回 false
        if (leftNode == nullptr || rightNode == nullptr) {
            return false;
        }
        // 终止条件 3：两个都不为空，但值不相等，返回 false
        if (leftNode->val != rightNode->val) {
            return false;
        }

        // 核心递归逻辑：
        // 1. 比较“外侧”：左节点的左孩子 vs 右节点的右孩子
        bool outside = checkMirror(leftNode->left, rightNode->right);
        
        // 2. 比较“内侧”：左节点的右孩子 vs 右节点的左孩子
        bool inside = checkMirror(leftNode->right, rightNode->left);

        // 只有内外侧同时对称，这两棵子树才算真正的镜像
        return outside && inside;
    }
};

