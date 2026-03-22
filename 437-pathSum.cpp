// 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

#include <stdio.h>
#include <vector>
#include <algorithm>
#include<unordered_set>
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
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        return path(root, targetSum);
    }

    int path(TreeNode* root, int residueSum){
        if(!root)
            return 0;
        printf("_%d_%d_ ", root->val,residueSum);
        if((residueSum-root->val) == 0){
            printf("residueSum-root->val =0 :%d \n", root->val);

            return pathSum(root->left, target) + pathSum(root->right, target) +1+pathSum(root->left,0) + pathSum(root->right, 0);
        }   
        else 
            return pathSum(root->left, residueSum - root->val) + pathSum(root->right, residueSum - root->val)+pathSum(root->left, target) + pathSum(root->right, target);
    }
    int target = 0;
};