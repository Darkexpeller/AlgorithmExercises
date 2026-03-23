// 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

#include <stdio.h>
#include <vector>
#include <algorithm>
#include<unordered_set>
#include<unordered_map>
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
        unordered_map<int,int> prefix_sum_map;
        prefix_sum_map[0] = 1;
        return path(root, targetSum, prefix_sum_map,0);

    }

    int path(TreeNode* root, int targetSum,unordered_map<int,int> &prefix_sum_map,int prefix){
        if(!root)
            return 0;
        int left=0;
        int right = 0;
        int thispath = 0;
        int curr_sum = prefix + root->val;
        prefix_sum_map[curr_sum]++;

        auto it = prefix_sum_map.find(curr_sum - targetSum);
        if( prefix_sum_map.count(curr_sum - targetSum))
            thispath = prefix_sum_map[curr_sum - targetSum];

        if (root->left){
            left = path(root, targetSum, prefix_sum_map, root->val + prefix);
            //prefix_sum_map[root->val + prefix + root->left->val]--;
        }
       

        if (root->right){
            right = path(root, targetSum, prefix_sum_map, root->val + prefix);
            //prefix_sum_map[root->val + prefix + root->right->val]--;
        }
        prefix_sum_map[curr_sum]--;
        return thispath + left + right;
        }
};