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
    vector<int> inorderTraversal(TreeNode* root) {
		// 迭代方法 时间复杂度O(n),空间复杂度O(n)
        vector<int> res;
        stack<TreeNode*> stackTree;
        while (root != nullptr || !stackTree.empty()) {
            while (root != nullptr) {
                stackTree.push(root);
                root = root->left;
            }
            root = stackTree.top();
            stackTree.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
	
	// void inorder(TreeNode* root, vector<int>& res) {
	// 递归方法 时间复杂度O(n),空间复杂度O(n)
    //     if (!root) {
    //         return;
    //     }
    //     inorder(root->left, res);
    //     res.push_back(root->val);
    //     inorder(root->right, res);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     inorder(root, res);
    //     return res;
    // }
    };