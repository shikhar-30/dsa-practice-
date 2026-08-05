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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root==p || root==q) return root;
        TreeNode* left=lca(root->left,p,q);
        TreeNode* right=lca(root->right,p,q);
        if(left==NULL) return right;
        else if(right==NULL) return left;
        return root;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> leafs;
        while(!q.empty()){
            int size=q.size();
            leafs.clear();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                leafs.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        TreeNode* ans=leafs[0];
        for(int i=1;i<leafs.size();i++){
            ans=lca(root,ans,leafs[i]);
        }
        return ans;
    }
};