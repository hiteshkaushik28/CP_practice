/* Binary tree maximum path sum
 * Question Link:://leetcode.com/problems/binary-tree-maximum-path-sum/submissions
 * The idea is as follows:
 * Every node x will tell its parent y the value: max(val(x), val(x) + val(left-subtree(x)), val(x) + val(right-subtree(x))).
 * Reason: A path is any sequence of edges each of which either goes from parent to child or child to parent.
 * If the node x is itself a part of a big max path, then the maximum path cannot have both of its children because we can go to   either path that includes x's left child or the one with x's right child or only the node x itself.
 * Now we will also find the max sum of the current subtree. We need this because it is possible that the global max path lies
 * in this subtree rooted at x instead of the entire tree.
 * Using this value, we will modify our ans variable.
*/

Class Solution{
public:
    
    int maxsum(TreeNode* root, int& ans)
    {
        if(!root)
            return 0;
        int left = maxsum(root->left, ans);
        int right = maxsum(root->right, ans);
        int temp1 = max(root->val, max(left, right) + root->val);
        int temp2 = max(temp1, root->val + left + right);
        ans = max(ans, temp2);
        return temp1;
    }
    
    int maxPathSum(TreeNode* root)
    {
        int ans;
        maxsum(root, ans);
        return ans;
    }
};
