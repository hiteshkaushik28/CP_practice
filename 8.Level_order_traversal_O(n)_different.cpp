/* Return the Level Order traversal of a tree
 * Question Link:https://leetcode.com/problems/binary-tree-level-order-traversal/submissions 
 * The solution in Linear i.e O(n) and is a nice way to solve the problem.
*/
Class Solution{
public:

void level(TreeNode* root, int depth, vector<vector<int>>& ans){
    if(!root)
        return;
    if(ans.size() == depth)
        ans.push_back(vector<int>());

    ans[depth].push_back(root->val);
    level(root->left, depth + 1, ans);
    level(root->right, depth + 1, ans);
}

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> ans;
    level(root, 0, ans); // the vector can be made global also
    return ans;
}
};

