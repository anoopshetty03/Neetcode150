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
    bool dfs(TreeNode*root,TreeNode*target)
    {
     if(root==NULL && target==NULL)
        return true;

     if(root==NULL || target==NULL)
        return false;

     if(root->val == target->val)
        return dfs(root->left,target->left) && dfs(root->right,target->right);
     else 
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL)
            return false;
        
        else if(dfs(root, subRoot))
            return true;
        
        else
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};