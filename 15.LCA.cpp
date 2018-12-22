/* Lowest Common Ancestor
 * Question Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 * Bloody 4 line solution
 * This doesn't handle duplicate keys in the tree, one node not present in the tree cases.
*/

Class Solution{
public:
    lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root || root->val == p->val || root->val == q->val) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        return (!left ? right : !right ? left : root); // beautiful compression
    }
};
