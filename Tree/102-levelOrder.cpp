#include <iostream>
#include <vector>
#include <queue>
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

//数组转链表
TreeNode* arrayToTree(const vector<int>& arr,int index)
{
    if(index>=arr.size()) return nullptr;
    TreeNode* root=new TreeNode(arr[index]);
    root->left=arrayToTree(arr,2*index+1);
    root->right=arrayToTree(arr,2*index+2);
    return root;
}



class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode*> que;
        if(root) que.push(root);
        vector<vector<int>> result;
        int QueSize=0;
        while (!que.empty())
        {
            QueSize=que.size();
            vector<int> vec;
            TreeNode* top;
            for(int i=0;i<QueSize;++i)
            {
                top=que.front();

                que.pop();
                vec.push_back(top->val);
                if(top->left)   que.push(top->left);
                if(top->right)  que.push(top->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};
