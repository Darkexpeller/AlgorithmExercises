#include <stdio.h>
#include <vector>
#include <algorithm>
#include<stack>
#include <queue>
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
TreeNode* buildTree(vector<int> nums) {
    if (nums.empty() || nums[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nums.size()) {
        TreeNode* current = q.front();
        q.pop();

        // 处理左子节点
        if (i < nums.size() && nums[i] != -1) { // 假设 -1 代表 null
            current->left = new TreeNode(nums[i]);
            q.push(current->left);
        }
        i++;

        // 处理右子节点
        if (i < nums.size() && nums[i] != -1) {
            current->right = new TreeNode(nums[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root){
        vector<int> result;
        if(root==nullptr)
            return result;
        stack<TreeNode *> st;
        TreeNode * LastVisited=nullptr;//主要是用来标记子树是否被访问
        TreeNode *current = root;
        st.push(root);
        while(!st.empty()){
            current = st.top();
            if(current->right!=NULL &&current->right == LastVisited) //如果右节点被记录了，说明当前子树已经被遍历完成，当前节点可以出栈，子树被标记为已访问。
            {
                //result.push_back(current->val);//后序遍历
                st.pop();
                LastVisited=current;
                continue;
            }
            if(current->left==nullptr || current->left == LastVisited ) //若左节点已访问，或者左节点为空，则遍历到了当前节点，需要输出值
            {
                result.push_back(current->val);
                
                
                if(current->right!=nullptr) //如果右节点非空则将右节点压入栈以开始其遍历
                {
                    st.push(current->right);
                }
                else{//右节点为空说明以当前节点为根的子树遍历完成
                    st.pop();
                    LastVisited=current;
                }
                    
                continue;
            }
            if(current->left !=nullptr){ //前两个状态都不是说明是第一次经过该节点，开始遍历其左节点
                //result.push_back(current->val);//后序遍历
                st.push(current->left);
                continue;
            }   
        }
        return result;
    }

};


int main(){
    vector<int> tree = {1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9};
    Solution s;
    auto in =buildTree(tree);
    printf("tree=%X\n", in);
    auto ret = s.inorderTraversal(in);
    
    for(int num:ret){
        printf("%d ", num);
    }
}