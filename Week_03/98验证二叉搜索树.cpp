/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
long last = LONG_MIN;
bool flag = true;
    bool isValidBST(TreeNode* root) {
		if(!root)
			return true;
		
		//遍历左子树
        if(flag && root->left)
			isValidBST(root->left);
		
		//当前节点不大于父节点，不是二叉搜索树
		if(root->val <= last)
			flag = false;
		
		last = root->val; // 记录父节点值
		
		//遍历右子树
		if(flag && root->right)
			isValidBST(root->right);
		
		//子树都遍历完 || 不是二叉搜索树，就退出
		return flag;
    }
};